-- Language-specific Plugins

return {
  -- Python
  {
    "vim-scripts/indentpython.vim",
    ft = "python",
  },

  -- C/C++ - Doxygen
  {
    "vim-scripts/DoxygenToolkit.vim",
    ft = { "c", "cpp" },
    keys = {
      { "<C-d>", "<cmd>Dox<cr>", desc = "Generate Doxygen comment", ft = { "c", "cpp" } },
    },
  },

  -- Cscope
  {
    "dhananjaylatkar/cscope_maps.nvim",
    dependencies = {
      "folke/which-key.nvim",
      "nvim-telescope/telescope.nvim", -- optional
    },
    ft = { "c", "cpp" },
    config = function()
      require("cscope_maps").setup({
        disable_maps = false,
        cscope = {
          db_file = "./cscope.out",
          exec = "cscope",
          picker = "quickfix", -- or "telescope"
          skip_input_prompt = true,
        },
      })
    end,
  },

  -- Terraform
  {
    "hashivim/vim-terraform",
    ft = { "terraform", "tf", "hcl" },
    config = function()
      vim.g.terraform_align = 1
      vim.g.terraform_fmt_on_save = 1
    end,
  },

  -- Kubernetes/YAML
  {
    "cuducos/yaml.nvim",
    ft = { "yaml", "yml" },
    dependencies = {
      "nvim-treesitter/nvim-treesitter",
    },
  },

  -- Dockerfile
  {
    "ekalinin/Dockerfile.vim",
    ft = "dockerfile",
  },

  -- Ansible
  {
    "pearofducks/ansible-vim",
    ft = { "yaml.ansible", "ansible" },
  },
}
