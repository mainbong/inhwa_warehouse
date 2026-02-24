-- Coding Plugins with Node.js Fallback
-- If Node.js is not available, use Neovim's built-in LSP instead of CoC

-- Check if Node.js is available
local function has_node()
  return vim.fn.executable('node') == 1
end

local function has_npm()
  return vim.fn.executable('npm') == 1
end

-- Only use CoC if Node.js is available
if has_node() and has_npm() then
  return {
    -- CoC.nvim (requires Node.js)
    {
      "neoclide/coc.nvim",
      branch = "release",
      event = { "BufReadPost", "BufNewFile" },
      config = function()
        -- CoC extensions to install automatically
        vim.g.coc_global_extensions = {
          'coc-json',
          'coc-tsserver',
          'coc-pyright',
          'coc-yaml',
          'coc-sh',
          'coc-clangd',
          'coc-cmake',
          'coc-docker',
          'coc-go',
          'coc-rust-analyzer',
        }

        -- Use tab for trigger completion
        local keyset = vim.keymap.set
        local opts = {silent = true, noremap = true, expr = true, replace_keycodes = false}

        function _G.check_back_space()
          local col = vim.fn.col('.') - 1
          return col == 0 or vim.fn.getline('.'):sub(col, col):match('%s') ~= nil
        end

        -- Tab completion
        keyset("i", "<TAB>", 'coc#pum#visible() ? coc#pum#next(1) : v:lua.check_back_space() ? "<TAB>" : coc#refresh()', opts)
        keyset("i", "<S-TAB>", [[coc#pum#visible() ? coc#pum#prev(1) : "\<C-h>"]], opts)

        -- Enter to confirm completion
        keyset("i", "<cr>", [[coc#pum#visible() ? coc#pum#confirm() : "\<C-g>u\<CR>\<c-r>=coc#on_enter()\<CR>"]], opts)

        -- Use <c-space> to trigger completion
        keyset("i", "<c-space>", "coc#refresh()", {silent = true, expr = true})

        -- GoTo code navigation
        keyset("n", "gd", "<Plug>(coc-definition)", {silent = true})
        keyset("n", "gy", "<Plug>(coc-type-definition)", {silent = true})
        keyset("n", "gi", "<Plug>(coc-implementation)", {silent = true})
        keyset("n", "gr", "<Plug>(coc-references)", {silent = true})

        -- Use K to show documentation
        function _G.show_docs()
          local cw = vim.fn.expand('<cword>')
          if vim.fn.index({'vim', 'help'}, vim.bo.filetype) >= 0 then
            vim.api.nvim_command('h ' .. cw)
          elseif vim.api.nvim_eval('coc#rpc#ready()') then
            vim.fn.CocActionAsync('doHover')
          else
            vim.api.nvim_command('!' .. vim.o.keywordprg .. ' ' .. cw)
          end
        end
        keyset("n", "K", '<CMD>lua _G.show_docs()<CR>', {silent = true})

        -- Rename
        keyset("n", "<leader>rn", "<Plug>(coc-rename)", {silent = true})

        -- Format
        keyset("x", "<leader>f", "<Plug>(coc-format-selected)", {silent = true})
        keyset("n", "<leader>f", "<Plug>(coc-format-selected)", {silent = true})

        -- Diagnostic navigation
        keyset("n", "[d", "<Plug>(coc-diagnostic-prev)", {silent = true})
        keyset("n", "]d", "<Plug>(coc-diagnostic-next)", {silent = true})

        -- Highlight symbol under cursor
        vim.api.nvim_create_augroup("CocGroup", {})
        vim.api.nvim_create_autocmd("CursorHold", {
          group = "CocGroup",
          command = "silent call CocActionAsync('highlight')",
          desc = "Highlight symbol under cursor on CursorHold"
        })

        -- Update signature help on jump placeholder
        vim.api.nvim_create_autocmd("User", {
          group = "CocGroup",
          pattern = "CocJumpPlaceholder",
          command = "call CocActionAsync('showSignatureHelp')",
          desc = "Update signature help on jump placeholder"
        })

        -- Show message when using CoC
        vim.notify("Using CoC.nvim (Node.js available)", vim.log.levels.INFO)
      end,
    },

    -- Treesitter (better syntax highlighting)
    {
      "nvim-treesitter/nvim-treesitter",
      lazy = false,  -- lazy-loading 미지원
      build = ":TSUpdate",
      config = function()
        -- 파서 설치
        require('nvim-treesitter').install({
          "c", "cpp", "python", "lua", "vim", "vimdoc",
          "bash", "javascript", "typescript", "json", "yaml",
          "go", "rust", "dockerfile", "terraform", "hcl"
        })
        -- 파일타입별 highlighting + indent 활성화
        vim.api.nvim_create_autocmd('FileType', {
          callback = function()
            local ok = pcall(vim.treesitter.start)
            if ok then
              vim.bo.indentexpr = "v:lua.require'nvim-treesitter'.indentexpr()"
            end
          end,
        })
      end,
    },
  }
else
  -- Fallback: Use Neovim's built-in LSP (no Node.js required)
  return {
    -- LSP Config
    {
      "neovim/nvim-lspconfig",
      event = { "BufReadPost", "BufNewFile" },
      dependencies = {
        "hrsh7th/cmp-nvim-lsp",
        "hrsh7th/cmp-buffer",
        "hrsh7th/cmp-path",
        "hrsh7th/nvim-cmp",
        "L3MON4D3/LuaSnip",
      },
      config = function()
        -- Setup nvim-cmp (completion)
        local cmp = require('cmp')
        cmp.setup({
          snippet = {
            expand = function(args)
              require('luasnip').lsp_expand(args.body)
            end,
          },
          mapping = cmp.mapping.preset.insert({
            ['<C-b>'] = cmp.mapping.scroll_docs(-4),
            ['<C-f>'] = cmp.mapping.scroll_docs(4),
            ['<C-Space>'] = cmp.mapping.complete(),
            ['<C-e>'] = cmp.mapping.abort(),
            ['<CR>'] = cmp.mapping.confirm({ select = true }),
            ['<Tab>'] = cmp.mapping(function(fallback)
              if cmp.visible() then
                cmp.select_next_item()
              else
                fallback()
              end
            end, { 'i', 's' }),
            ['<S-Tab>'] = cmp.mapping(function(fallback)
              if cmp.visible() then
                cmp.select_prev_item()
              else
                fallback()
              end
            end, { 'i', 's' }),
          }),
          sources = cmp.config.sources({
            { name = 'nvim_lsp' },
            { name = 'luasnip' },
          }, {
            { name = 'buffer' },
            { name = 'path' },
          })
        })

        -- LSP keymaps: LspAttach 방식 (nvim 0.11+ 권장)
        vim.api.nvim_create_autocmd('LspAttach', {
          callback = function(args)
            local opts = { noremap = true, silent = true, buffer = args.buf }
            vim.keymap.set('n', 'gd', vim.lsp.buf.definition, opts)
            vim.keymap.set('n', 'K', vim.lsp.buf.hover, opts)
            vim.keymap.set('n', 'gi', vim.lsp.buf.implementation, opts)
            vim.keymap.set('n', 'gr', vim.lsp.buf.references, opts)
            vim.keymap.set('n', '<leader>rn', vim.lsp.buf.rename, opts)
            vim.keymap.set('n', '[d', vim.diagnostic.goto_prev, opts)
            vim.keymap.set('n', ']d', vim.diagnostic.goto_next, opts)
          end,
        })

        -- 전역 LSP 기본값: capabilities 를 모든 서버에 일괄 적용
        vim.lsp.config('*', {
          capabilities = require('cmp_nvim_lsp').default_capabilities(),
        })

        -- 서버별 추가 설정 (custom settings 가 있는 것만)
        vim.lsp.config('lua_ls', {
          settings = {
            Lua = { diagnostics = { globals = { 'vim' } } }
          }
        })

        vim.lsp.config('gopls', {
          settings = {
            gopls = {
              analyses = { unusedparams = true },
              staticcheck = true,
            }
          }
        })

        vim.lsp.config('yamlls', {
          settings = {
            yaml = {
              schemas = {
                kubernetes = "/*.yaml",
                ["http://json.schemastore.org/github-workflow"] = ".github/workflows/*",
                ["http://json.schemastore.org/github-action"] = ".github/action.{yml,yaml}",
                ["http://json.schemastore.org/ansible-stable-2.9"] = "roles/tasks/*.{yml,yaml}",
                ["http://json.schemastore.org/prettierrc"] = ".prettierrc.{yml,yaml}",
                ["http://json.schemastore.org/kustomization"] = "kustomization.{yml,yaml}",
                ["http://json.schemastore.org/chart"] = "Chart.{yml,yaml}",
                ["https://json.schemastore.org/dependabot-v2"] = ".github/dependabot.{yml,yaml}",
                ["https://raw.githubusercontent.com/compose-spec/compose-spec/master/schema/compose-spec.json"] = "*docker-compose*.{yml,yaml}",
              },
              format = { enable = true },
              validate = true,
              completion = true,
            }
          }
        })

        -- 서버 활성화 (실행파일 존재 여부 확인 후)
        -- Python
        if vim.fn.executable('pyright') == 1 then
          vim.lsp.enable('pyright')
        elseif vim.fn.executable('pylsp') == 1 then
          vim.lsp.enable('pylsp')
        end

        -- Bash
        if vim.fn.executable('bash-language-server') == 1 then
          vim.lsp.enable('bashls')
        end

        -- C/C++ (clangd)
        if vim.fn.executable('clangd') == 1 then
          vim.lsp.enable('clangd')
        end

        -- Lua
        if vim.fn.executable('lua-language-server') == 1 then
          vim.lsp.enable('lua_ls')
        end

        -- Go
        if vim.fn.executable('gopls') == 1 then
          vim.lsp.enable('gopls')
        end

        -- Rust
        if vim.fn.executable('rust-analyzer') == 1 then
          vim.lsp.enable('rust_analyzer')
        end

        -- JSON
        if vim.fn.executable('vscode-json-language-server') == 1 then
          vim.lsp.enable('jsonls')
        end

        -- TypeScript/JavaScript (tsserver → ts_ls 로 rename 됨)
        if vim.fn.executable('typescript-language-server') == 1 then
          vim.lsp.enable('ts_ls')
        end

        -- YAML
        if vim.fn.executable('yaml-language-server') == 1 then
          vim.lsp.enable('yamlls')
        end

        -- CMake
        if vim.fn.executable('cmake-language-server') == 1 then
          vim.lsp.enable('cmake')
        end

        -- Docker
        if vim.fn.executable('docker-langserver') == 1 then
          vim.lsp.enable('dockerls')
        end

        -- Show message when using native LSP
        vim.notify("Using Neovim native LSP (Node.js not available)", vim.log.levels.INFO)
      end,
    },

    -- nvim-cmp and dependencies
    { "hrsh7th/nvim-cmp", lazy = true },
    { "hrsh7th/cmp-nvim-lsp", lazy = true },
    { "hrsh7th/cmp-buffer", lazy = true },
    { "hrsh7th/cmp-path", lazy = true },
    { "L3MON4D3/LuaSnip", lazy = true },

    -- Treesitter (better syntax highlighting)
    {
      "nvim-treesitter/nvim-treesitter",
      lazy = false,  -- lazy-loading 미지원
      build = ":TSUpdate",
      config = function()
        -- 파서 설치
        require('nvim-treesitter').install({
          "c", "cpp", "python", "lua", "vim", "vimdoc",
          "bash", "json", "yaml", "dockerfile", "terraform", "hcl"
        })
        -- 파일타입별 highlighting + indent 활성화
        vim.api.nvim_create_autocmd('FileType', {
          callback = function()
            local ok = pcall(vim.treesitter.start)
            if ok then
              vim.bo.indentexpr = "v:lua.require'nvim-treesitter'.indentexpr()"
            end
          end,
        })
      end,
    },
  }
end
