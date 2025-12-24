-- Neovim Key Mappings (migrated from .vimrc)

local map = vim.keymap.set
local opts = { noremap = true, silent = true }

-- Set leader key
vim.g.mapleader = '\\'
vim.g.maplocalleader = '\\'

-- File navigation (will be updated after plugin installation)
-- Ctrl+P for fuzzy finder (fzf)
map('n', '<C-p>', ':Files<CR>', opts)

-- NERDTree / nvim-tree toggle
map('n', '<C-n>', ':NvimTreeToggle<CR>', opts)

-- Tagbar toggle
map('n', '<F9>', ':TagbarToggle<CR>', opts)

-- Help toggle (custom function - will implement later)
map('n', '<F1>', ':help<CR>', opts)

-- Copy and paste (system clipboard)
map('v', '<C-c>', '"+y', opts)
map('v', '<C-x>', '"+c', opts)
map('v', '<C-v>', 'c<ESC>"+p', opts)
map('i', '<C-v>', '<ESC>"+pa', opts)

-- Disable Insert key entering replace mode
map('i', '<Insert>', '<Nop>', opts)
map('i', '<S-Insert>', '<Insert>', opts)

-- Buffer management
map('n', '<leader><Tab>', ':enew<CR>', opts)        -- new buffer
map('n', '<Tab>', ':bnext<CR>', opts)               -- next buffer
map('n', '<S-Tab>', ':bprevious<CR>', opts)         -- previous buffer
map('n', '<leader>q', ':bdelete<CR>', opts)         -- close buffer
map('n', '<leader>bl', ':ls<CR>', opts)             -- list buffers

-- Mouse toggle (for copy-paste)
map('n', '<F3>', ':set nonu<CR>:set mouse=r<CR>', opts)
map('n', '<F4>', ':set nu<CR>:set mouse=a<CR>', opts)

-- Scroll wheel
map('n', '<ScrollWheelUp>', '<C-Y>', opts)
map('n', '<ScrollWheelDown>', '<C-E>', opts)

-- Cscope mappings (if available)
if vim.fn.has('cscope') == 1 then
  -- Cscope find commands
  map('n', '<C-\\>s', ':cs find s <C-R>=expand("<cword>")<CR><CR>', opts)
  map('n', '<C-\\>g', ':cs find g <C-R>=expand("<cword>")<CR><CR>', opts)
  map('n', '<C-\\>c', ':cs find c <C-R>=expand("<cword>")<CR><CR>', opts)
  map('n', '<C-\\>t', ':cs find t <C-R>=expand("<cword>")<CR><CR>', opts)
  map('n', '<C-\\>e', ':cs find e <C-R>=expand("<cword>")<CR><CR>', opts)
  map('n', '<C-\\>f', ':cs find f <C-R>=expand("<cfile>")<CR><CR>', opts)
  map('n', '<C-\\>i', ':cs find i <C-R>=expand("<cfile>")<CR><CR>', opts)
  map('n', '<C-\\>d', ':cs find d <C-R>=expand("<cword>")<CR><CR>', opts)
end

-- Quickfix navigation (for cscope results)
map('n', ']q', ':cnext<CR>', opts)
map('n', '[q', ':cprev<CR>', opts)

-- Window navigation
map('n', '<C-h>', '<C-w>h', opts)
map('n', '<C-j>', '<C-w>j', opts)
map('n', '<C-k>', '<C-w>k', opts)
map('n', '<C-l>', '<C-w>l', opts)

-- YCM/CoC Go to definition (will be configured in CoC plugin)
-- map('n', '<leader>g', '<Plug>(coc-definition)', opts)

-- Multi-cursor (will be configured if plugin is installed)
-- Using default multi-cursor mappings

-- Clear search highlight
map('n', '<Esc>', ':noh<CR>', opts)
