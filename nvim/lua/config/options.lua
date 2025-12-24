-- Neovim Options (migrated from .vimrc)

local opt = vim.opt

-- Encoding
vim.scriptencoding = 'utf-8'
opt.encoding = 'utf-8'
opt.fileencodings = 'utf-8,euc-kr'

-- Display
opt.number = true           -- set nu
opt.cursorline = true       -- highlight current line
opt.cursorcolumn = true     -- highlight current column
opt.colorcolumn = '80'      -- 80 char column marker
opt.laststatus = 2          -- always show statusline
opt.termguicolors = true    -- enable 24-bit RGB colors

-- Indentation
opt.autoindent = true       -- auto indent
opt.tabstop = 4             -- ts=4
opt.shiftwidth = 4          -- sw=4
opt.expandtab = true        -- et (use spaces instead of tabs)
opt.smarttab = true
opt.shiftround = true

-- Search
opt.ignorecase = true       -- ic (ignore case in search)
opt.smartcase = true        -- smart case sensitivity
opt.incsearch = true        -- is (incremental search)
opt.hlsearch = true         -- highlight search results

-- Editor behavior
opt.hidden = true           -- allow hidden buffers
opt.mouse = 'a'             -- enable mouse
opt.background = 'dark'     -- dark background
opt.completeopt = 'longest,menuone' -- completion menu settings

-- Visual
opt.list = true
opt.listchars = {
  tab = '»·',
  trail = '·',
  extends = '$',
  nbsp = '=',
}

-- Disable swap files (optional)
opt.swapfile = false
opt.backup = false
opt.writebackup = false

-- Undo
opt.undofile = true
opt.undodir = vim.fn.stdpath("data") .. "/undo"

-- Clipboard
opt.clipboard = 'unnamedplus' -- use system clipboard

-- Performance
opt.updatetime = 300
opt.timeoutlen = 500

-- Enable filetype detection
vim.cmd('filetype plugin indent on')
vim.cmd('syntax enable')

-- Colorscheme (molokai replacement - will be set after plugins load)
vim.g.python_highlight_all = 1
