# Modern Neovim Configuration

> Migrated from Vundle + .vimrc to lazy.nvim + Lua configuration
> Optimized for cloud infrastructure development (DevOps/SRE)

## ✨ Features

- **Modern Plugin Manager**: lazy.nvim with auto lazy-loading
- **Smart Completion**:
  - CoC.nvim (when Node.js is available)
  - Native LSP + nvim-cmp (fallback for servers without Node.js)
- **Fast File Navigation**: fzf.vim (CtrlP replacement)
- **Advanced Syntax**: Treesitter for better highlighting
- **Git Integration**: Fugitive + Gitsigns
- **Cloud-Friendly**: Supports Terraform, Kubernetes, Docker, Ansible

## 📦 Installation

### Quick Start (New Machine)

```bash
# Install Neovim
## macOS
brew install neovim

## Ubuntu/Debian
sudo apt install neovim

## From source (latest)
sudo add-apt-repository ppa:neovim-ppa/stable
sudo apt update && sudo apt install neovim

# Clone configuration
git clone https://github.com/mainbong/inhwa_warehouse.git
cd inhwa_warehouse
cp -r nvim ~/.config/

# Launch Neovim (plugins will auto-install)
nvim
```

### Optional: Node.js (for CoC.nvim)

```bash
# macOS
brew install node

# Ubuntu/Debian
curl -fsSL https://deb.nodesource.com/setup_lts.x | sudo -E bash -
sudo apt-get install -y nodejs

# Without Node.js: Native LSP will be used automatically
```

## 🔧 Configuration Structure

```
~/.config/nvim/
├── init.lua                    # Main entry point
├── lua/
│   ├── config/
│   │   ├── options.lua        # Editor options
│   │   └── keymaps.lua        # Key mappings
│   └── plugins/
│       ├── ui.lua             # Colorscheme, statusline, bufferline
│       ├── editor.lua         # File explorer, fuzzy finder, motions
│       ├── coding.lua         # Completion (CoC or native LSP)
│       ├── git.lua            # Git integration
│       └── lang.lua           # Language-specific plugins
└── README.md                  # This file
```

## ⌨️ Key Bindings

### File Navigation
| Key | Action |
|-----|--------|
| `Ctrl+p` | Fuzzy file finder (fzf) |
| `Ctrl+n` | Toggle file tree (nvim-tree) |
| `<leader>fg` | Grep search |
| `<leader>fb` | Find buffers |

### Buffer Management
| Key | Action |
|-----|--------|
| `Tab` | Next buffer |
| `Shift+Tab` | Previous buffer |
| `<leader><Tab>` | New buffer |
| `<leader>q` | Close buffer |
| `<leader>bl` | List buffers |

### Code Navigation
| Key | Action |
|-----|--------|
| `gd` | Go to definition |
| `gr` | Find references |
| `K` | Show documentation |
| `<leader>rn` | Rename symbol |
| `[d` / `]d` | Previous/Next diagnostic |

### Git
| Key | Action |
|-----|--------|
| `<leader>gs` | Git status |
| `<leader>gb` | Git blame |
| `<leader>gd` | Git diff |
| `]c` / `[c` | Next/Previous git hunk |

### Code Editing
| Key | Action |
|-----|--------|
| `Tab` | Next completion item |
| `Shift+Tab` | Previous completion item |
| `Ctrl+Space` | Trigger completion |
| `s` | Flash jump (quick motion) |
| `gc` | Comment toggle |

### Tags & Outline
| Key | Action |
|-----|--------|
| `F9` | Toggle Tagbar |
| `Ctrl+]` | Jump to tag |

### Cscope (C/C++)
| Key | Action |
|-----|--------|
| `Ctrl+\` + `s` | Find symbol |
| `Ctrl+\` + `g` | Find definition |
| `Ctrl+\` + `c` | Find callers |
| `Ctrl+\` + `f` | Find file |
| `]q` / `[q` | Next/Previous result |

## 📋 Plugin List

### Core
- **lazy.nvim** - Plugin manager
- **tokyonight.nvim** - Colorscheme (molokai alternative)
- **nvim-treesitter** - Advanced syntax highlighting

### Completion & LSP
- **coc.nvim** - VSCode-like completion (if Node.js available)
- **nvim-lspconfig** + **nvim-cmp** - Native LSP fallback
- Supported languages: Python, Bash, C/C++, Go, Rust, Terraform, YAML, etc.

### Editor
- **nvim-tree.lua** - File explorer (NERDTree replacement)
- **fzf.vim** - Fuzzy finder (CtrlP replacement)
- **flash.nvim** - Fast motion (EasyMotion replacement)
- **vim-visual-multi** - Multiple cursors
- **tagbar** - Code outline
- **Comment.nvim** - Smart comments
- **nvim-autopairs** - Auto close brackets

### Git
- **vim-fugitive** - Git commands
- **gitsigns.nvim** - Git decorations & hunks

### UI
- **lualine.nvim** - Statusline (vim-airline replacement)
- **bufferline.nvim** - Buffer tabs
- **which-key.nvim** - Key binding hints
- **indent-blankline.nvim** - Indent guides

### Language Support
- **Terraform** - HCL syntax, auto-format
- **Kubernetes/YAML** - Schema validation
- **Docker** - Dockerfile syntax
- **Ansible** - Playbook support
- **Python** - Indentation, flake8
- **C/C++** - Doxygen, cscope integration

## 🚀 Usage for Cloud Infrastructure

### Terraform
```vim
:edit main.tf
" Auto-format on save is enabled
" LSP provides completion for resources
```

### Kubernetes YAML
```vim
:edit deployment.yaml
" Schema validation via LSP
" Fuzzy search across manifests with Ctrl+p
```

### Jump Server Workflow
```bash
# SSH to jump server
ssh jump-server

# Neovim works instantly (no GUI needed)
nvim kubernetes-config.yaml

# Even without Node.js, native LSP works!
```

## 🔄 Migration from Old Vim Setup

### What Changed
| Old | New |
|-----|-----|
| Vundle | lazy.nvim |
| neocomplcache | CoC.nvim / nvim-lsp |
| CtrlP | fzf.vim |
| NERDTree | nvim-tree.lua |
| vim-airline | lualine.nvim |
| syntastic | LSP diagnostics |
| EasyMotion | flash.nvim |

### What Stayed
| Plugin | Status |
|--------|--------|
| vim-fugitive | ✅ Kept |
| tagbar | ✅ Kept |
| cscope | ✅ Modernized (cscope_maps.nvim) |
| Doxygen | ✅ Kept |
| a.vim | ✅ Kept |

## 🛠️ Troubleshooting

### Plugins not installing
```vim
:Lazy sync
```

### CoC not working
```bash
# Check Node.js
node --version

# If no Node.js, native LSP will be used automatically
# Install CoC extensions manually if needed
:CocInstall coc-json coc-pyright
```

### LSP not working (without Node.js)
```bash
# Install language servers via system package manager
# Python
pip install pyright

# Bash
npm install -g bash-language-server  # or use system package

# C/C++
sudo apt install clangd
```

### Performance issues
```vim
# Check startup time
nvim --startuptime startup.log

# Disable treesitter for specific file types
" Add to lua/config/options.lua
vim.g.loaded_perl_provider = 0
vim.g.loaded_ruby_provider = 0
```

## 📚 Additional Resources

- [lazy.nvim documentation](https://github.com/folke/lazy.nvim)
- [CoC.nvim extensions](https://github.com/neoclide/coc.nvim/wiki/Using-coc-extensions)
- [Neovim LSP guide](https://neovim.io/doc/user/lsp.html)

## 🤝 Contributing

This is a personal configuration, but feel free to fork and adapt for your needs!

## 📝 License

MIT
