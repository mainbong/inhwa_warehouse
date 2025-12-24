-- Neovim Configuration (Migrated from .vimrc)
-- Author: Inhwa.Ma
-- Modern setup with lazy.nvim

-- Bootstrap lazy.nvim
local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not vim.loop.fs_stat(lazypath) then
  vim.fn.system({
    "git",
    "clone",
    "--filter=blob:none",
    "https://github.com/folke/lazy.nvim.git",
    "--branch=stable",
    lazypath,
  })
end
vim.opt.rtp:prepend(lazypath)

-- Load core configurations
require("config.options")
require("config.keymaps")

-- Setup lazy.nvim with plugins
require("lazy").setup("plugins", {
  defaults = {
    lazy = true, -- lazy load plugins by default
  },
  performance = {
    rtp = {
      disabled_plugins = {
        "gzip",
        "matchit",
        "matchparen",
        "netrwPlugin",
        "tarPlugin",
        "tohtml",
        "tutor",
        "zipPlugin",
      },
    },
  },
  checker = {
    enabled = true, -- check for plugin updates
    notify = false,
  },
  change_detection = {
    notify = false,
  },
})
