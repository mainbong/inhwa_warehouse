-- Editor Enhancement Plugins

return {
  -- File explorer (NERDTree replacement)
  {
    "nvim-tree/nvim-tree.lua",
    dependencies = "nvim-tree/nvim-web-devicons",
    cmd = { "NvimTreeToggle", "NvimTreeFocus" },
    keys = {
      { "<C-n>", "<cmd>NvimTreeToggle<cr>", desc = "Toggle NvimTree" },
    },
    config = function()
      require("nvim-tree").setup({
        view = {
          width = 30,
        },
        renderer = {
          group_empty = true,
        },
        filters = {
          dotfiles = false,
        },
        git = {
          enable = true,
          ignore = false,
        },
      })
    end,
  },

  -- Fuzzy finder (CtrlP replacement)
  {
    "junegunn/fzf",
    build = "./install --all",
  },
  {
    "junegunn/fzf.vim",
    dependencies = "junegunn/fzf",
    cmd = { "Files", "Rg", "Buffers", "GFiles" },
    keys = {
      { "<C-p>", "<cmd>Files<cr>", desc = "Find Files" },
      { "<leader>fg", "<cmd>Rg<cr>", desc = "Grep" },
      { "<leader>fb", "<cmd>Buffers<cr>", desc = "Find Buffers" },
    },
    config = function()
      -- FZF layout
      vim.g.fzf_layout = { down = '40%' }

      -- Custom command to use cscope.files if available
      if vim.fn.filereadable('cscope.files') == 1 then
        vim.env.FZF_DEFAULT_COMMAND = 'cat cscope.files'
      end
    end,
  },

  -- Fast motion (EasyMotion replacement)
  {
    "folke/flash.nvim",
    event = "VeryLazy",
    opts = {},
    keys = {
      { "s", mode = { "n", "x", "o" }, function() require("flash").jump() end, desc = "Flash" },
      { "S", mode = { "n", "o", "x" }, function() require("flash").treesitter() end, desc = "Flash Treesitter" },
    },
  },

  -- Multiple cursors
  {
    "mg979/vim-visual-multi",
    event = "VeryLazy",
    init = function()
      vim.g.VM_maps = {
        ["Find Under"] = "<C-m>",
        ["Find Subword Under"] = "<C-m>",
      }
    end,
  },

  -- Auto pairs
  {
    "windwp/nvim-autopairs",
    event = "InsertEnter",
    config = function()
      require("nvim-autopairs").setup({})
    end,
  },

  -- Comments
  {
    "numToStr/Comment.nvim",
    event = "VeryLazy",
    config = function()
      require("Comment").setup()
    end,
  },

  -- Surround
  {
    "kylechui/nvim-surround",
    event = "VeryLazy",
    config = function()
      require("nvim-surround").setup({})
    end,
  },

  -- Tagbar
  {
    "preservim/tagbar",
    cmd = "TagbarToggle",
    keys = {
      { "<F9>", "<cmd>TagbarToggle<cr>", desc = "Toggle Tagbar" },
    },
  },

  -- Unimpaired (bracket mappings)
  {
    "tpope/vim-unimpaired",
    event = "VeryLazy",
  },

  -- A.vim (alternate files)
  {
    "vim-scripts/a.vim",
    ft = { "c", "cpp" },
  },

  -- Highlight whitespace
  {
    "ntpeters/vim-better-whitespace",
    event = { "BufReadPost", "BufNewFile" },
    config = function()
      vim.g.better_whitespace_enabled = 1
      vim.g.strip_whitespace_on_save = 0
    end,
  },
}
