-- UI Plugins (colorscheme, statusline, etc)

return {
  -- Colorscheme (molokai alternative)
  {
    "folke/tokyonight.nvim",
    lazy = false,
    priority = 1000,
    config = function()
      require("tokyonight").setup({
        style = "night", -- storm, night, moon, day
        transparent = false,
      })
      vim.cmd([[colorscheme tokyonight-night]])
    end,
  },

  -- Alternative: Molokai (if you want to keep the original)
  -- {
  --   "tomasr/molokai",
  --   lazy = false,
  --   priority = 1000,
  --   config = function()
  --     vim.cmd([[colorscheme molokai]])
  --   end,
  -- },

  -- Statusline (vim-airline replacement)
  {
    "nvim-lualine/lualine.nvim",
    dependencies = { "nvim-tree/nvim-web-devicons" },
    event = "VeryLazy",
    config = function()
      require('lualine').setup {
        options = {
          theme = 'tokyonight',
          component_separators = { left = '', right = ''},
          section_separators = { left = '', right = ''},
          globalstatus = true,
        },
        sections = {
          lualine_a = {'mode'},
          lualine_b = {'branch', 'diff', 'diagnostics'},
          lualine_c = {'filename'},
          lualine_x = {'encoding', 'fileformat', 'filetype'},
          lualine_y = {'progress'},
          lualine_z = {'location'}
        },
        extensions = {'nvim-tree', 'fugitive'},
      }
    end,
  },

  -- Buffer line
  {
    "akinsho/bufferline.nvim",
    dependencies = "nvim-tree/nvim-web-devicons",
    event = "VeryLazy",
    config = function()
      require("bufferline").setup{
        options = {
          numbers = "buffer_id",
          diagnostics = "coc",
          show_buffer_close_icons = true,
          show_close_icon = false,
          separator_style = "slant",
        }
      }
    end,
  },

  -- Indent guides
  {
    "lukas-reineke/indent-blankline.nvim",
    event = { "BufReadPost", "BufNewFile" },
    main = "ibl",
    config = function()
      require("ibl").setup({
        indent = {
          char = "│",
        },
        scope = {
          enabled = true,
        },
      })
    end,
  },

  -- Which-key (shows keybindings)
  {
    "folke/which-key.nvim",
    event = "VeryLazy",
    config = function()
      require("which-key").setup({})
    end,
  },
}
