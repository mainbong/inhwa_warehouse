syntax enable
colorscheme molokai
scriptencoding utf-8
set encoding=utf-8
set fileencodings=utf-8,euc-kr

" Inhwa.Ma AutoIndent
set autoindent
filetype plugin indent on

set ic
set is
set nu
set ts=4 sw=4
set background=dark
set hlsearch
set laststatus=2
set et
set hidden
if &term == "xterm"
    set t_Co=256
endif
set cursorline
set cursorcolumn
"if version >= 703
if exists('+colorcolumn')
	set colorcolumn=80
endif

" To install vundle
" git clone https://github.com/gmarik/vundle.git  ~/.vim/bundle/vundle
" :BundleInstall
" Configuration for bundle itself {{{
set nocompatible
filetype off

set rtp+=~/.vim/bundle/vundle/
call vundle#rc()

" Let Vundle manage Vundle
" requried!
Bundle 'gmarik/vundle'

" }}}

" My Bundles {{{
"
" original repos on github
"Bundle 'minibufexpl.vim'
"Bundle 'fholgado/minibufexpl.vim'
Bundle 'EasyMotion'
Bundle 'chazy/cscope_maps'
Bundle 'autoload_cscope.vim'
Bundle 'gtags.vim'
Bundle 'Mark--Karkat'
"Bundle 'cscope_macros.vim'
Bundle 'Tagbar'
Bundle 'ctrlp.vim'
Bundle 'scrooloose/nerdtree'
Bundle 'Toggle-NERDTree-width'

Bundle 'fugitive.vim'
Bundle 'unimpaired.vim'
Bundle 'A.vim'
Bundle 'Shougo/neocomplcache.vim'
Bundle 'DoxygenToolkit.vim'
"Bundle 'Shougo/unite.vim'
"Bundle 'Shougo/neomru.vim'
"Bundle 'bling/vim-airline'
Bundle 'vim-airline/vim-airline'
Bundle 'vim-airline/vim-airline-themes'
Bundle 'terryma/vim-multiple-cursors'
Bundle 'tpope/vim-fugitive'

"For Python
Bundle 'vim-scripts/indentpython.vim'
Bundle 'Valloric/YouCompleteMe'
Bundle 'nvie/vim-flake8'
Bundle 'vim-syntastic/syntastic'

let python_highlight_all=1
syntax on
" non github repos
"Bundle 'git://git.wincent.com/command-t.git'
"Bundle 'git://localhost/wvim.git'
" ...

" }}}

filetype plugin on "required!
"
" Brief help
" :BundleList          - list configured bundles
" :BundleInstall(!)    - install(update) bundles
" :BundleSearch(!) foo - search(or refresh cache first) for foo
" :BundleClean(!)      - confirm(or auto-approve) removal of unused bundles
"
" see :h vundle for more details or wiki for FAQ
" NOTE: comments after Bundle command are not allowed..

" MyHelp {{{
let g:MyHelp="off"
fu! MyHelpToggle ()
    if g:MyHelp== "on"
        let g:MyHelp="off"
        bd "myhelp.txt"
    else
        let g:MyHelp="on"
        bo help myhelp
    endif
endfu
" }}}

" Key Mapping {{{

map <C-p> :CtrlPLastMode --dir<CR>
map <C-n> :NERDTreeToggle<CR>
map <C-d> :Dox<CR>
nnoremap <silent> <F9> :TagbarToggle<CR>
nnoremap <silent> <F1> :call MyHelpToggle()<CR>

map <Leader>b :MiniBufExplorer<cr>

" copy and paste
vmap <C-c> "+yi
vmap <C-x> "+c
vmap <C-v> c<ESC>"+p
imap <C-v> <ESC>"+pa

" disable entering replace mode by Insert key
imap <Insert> <Nop>
inoremap <S-Insert> <Insert>

" Open new buffer
nmap <leader><Tab> :enew<CR>

" Move Next buffer
nmap <Tab> :bnext<CR>
nmap <S-Tab> :bprevious<CR>

nmap <leader>q :bdelete<CR>

nmap <leader>bl :ls<CR>

" }}}


" airline configuration {{{
let g:airline_theme='minimalist'
set guifont=Dejavu\ Sans\ Mono\ for\ Powerline
let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#fnamemod = ':t'
let g:airline_powerline_fonts = 1
if !exists('g:airline_symbols')
let g:airline_symbols = {}
endif

" unicode symbols
let g:airline_left_sep = '»'
let g:airline_left_sep = '▶'
let g:airline_right_sep = '«'
let g:airline_right_sep = '◀'
let g:airline_symbols.crypt = '🔒'
let g:airline_symbols.linenr = '☰'
let g:airline_symbols.linenr = '␊'
let g:airline_symbols.linenr = '␤'
let g:airline_symbols.linenr = '¶'
let g:airline_symbols.maxlinenr = ''
let g:airline_symbols.maxlinenr = '㏑'
let g:airline_symbols.branch = '⎇'
let g:airline_symbols.paste = 'ρ'
let g:airline_symbols.paste = 'Þ'
let g:airline_symbols.paste = '∥'
let g:airline_symbols.spell = 'Ꞩ'
let g:airline_symbols.notexists = '∄'
let g:airline_symbols.whitespace = 'Ξ'

" powerline symbols
let g:airline_left_sep = ''
let g:airline_left_alt_sep = ''
let g:airline_right_sep = ''
let g:airline_right_alt_sep = ''
let g:airline_symbols.branch = ''
let g:airline_symbols.readonly = ''
let g:airline_symbols.linenr = '☰'
let g:airline_symbols.maxlinenr = ''

""  }}}

" mouse configuration {{{
set mouse=a

nmap <F3> :set nonu<CR> :set mouse=r<CR>
nmap <F4> :set nu<CR> :set mouse=a<CR>

map <ScrollWheelUp> <C-Y>
map <ScrollWheelDown> <C-E>
" }}}

" cscope configuration {{{
if has('cscope')
    if has('quickfix')
        set cscopequickfix=s-,c-,d-,i-,t-,e-,g-
        nnoremap <C-]>s :set cscopequickfix=s+<CR> :cs find s <C-R>=expand("<cword>")<CR><CR>
    endif
endif
" }}}

" ctrlp configuration {{{

"let g:ctrlp_cmd = 'exe "CtrlP".get(["","Buffer","MRU"], v:count)' "'CtrlP --dir'
let g:ctrlp_cmd = 'CtrlP --dir'
let g:ctrlp_working_path_mode = 'ra'
"let g:ctrlp_working_path_mode = '0'
let g:ctrlp_by_filename = 1
let g:ctrlp_root_markers = ['cscope.files']
let g:ctrlp_user_command = ['cscope.files', 'cat %s/cscope.files']
let g:ctrlp_max_files = 0
let g:ctrlp_lazy_update = 1
let g:ctrlp_max_height = 20
let g:ctrlp_use_caching = 0

let g:ctrlp_set_cwd = 0
function! s:setcwd()
  if exists('g:ctrlp_prj_dir') | retu | en
  let cph = expand('%:p:h', 1)
  if cph =~ '^.\+://' | retu | en
  for mkr in ['cscope.files']
    let wd = call('find'.(mkr =~ '/$' ? 'dir' : 'file'), [mkr, cph.';'])
    if wd != '' | let &acd = 0 | brea | en
  endfo
  let g:ctrlp_prj_dir = fnameescape(wd == '' ? cph : substitute(wd, mkr.'$', '.', ''))
  echom g:ctrlp_prj_dir
  exe 'lc!' fnameescape(wd == '' ? cph : substitute(wd, mkr.'$', '.', ''))
endfunction

autocmd BufEnter * call s:setcwd()




" }}}

" miniBufExplorer configuration {{{

    let g:miniBufExplShowBufNumbers = 10
" }}}

" NeoComplCacheEnable {{{
  " Use neocomplcache.
  let g:neocomplcache_enable_at_startup = 1
  " Use smartcase.
  let g:neocomplcache_enable_smart_case = 1
  " Use camel case completion.
  let g:neocomplcache_enable_camel_case_completion = 1
  " Use underbar completion.
  let g:neocomplcache_enable_underbar_completion = 1
  " Set minimum syntax keyword length.
  let g:neocomplcache_min_syntax_length = 3
  let g:neocomplcache_lock_buffer_name_pattern = '\*ku\*'

  " Define dictionary.
  let g:neocomplcache_dictionary_filetype_lists = {
      \ 'default' : '',
      \ 'vimshell' : $HOME.'/.vimshell_hist',
      \ 'scheme' : $HOME.'/.gosh_completions'
      \ }

  " Define keyword.
  if !exists('g:neocomplcache_keyword_patterns')
    let g:neocomplcache_keyword_patterns = {}
  endif
  let g:neocomplcache_keyword_patterns['default'] = '\h\w*'

  " Plugin key-mappings.
  imap <C-k>     <Plug>(neocomplcache_snippets_expand)
  smap <C-k>     <Plug>(neocomplcache_snippets_expand)
  inoremap <expr><C-g>     neocomplcache#undo_completion()
  inoremap <expr><C-l>     neocomplcache#complete_common_string()

  " <CR>: close popup and save indent.
  inoremap <silent> <CR> <C-r>=<SID>my_cr_function()<CR>
  function! s:my_cr_function()
     return (pumvisible() ? "\<C-y>" : "" ) . "\<CR>
     " For no inserting <CR> key.
     "return pumvisible() ? "\<C-y>" : "\<CR>"
  endfunction


  " <TAB>: completion.
  inoremap <expr><TAB>  pumvisible() ? "\<C-n>" :
        \ <SID>check_back_space() ? "\<TAB>" :
        \ neocomplcache#start_manual_complete()
  function! s:check_back_space() "{{{
     let col = col('.') - 1
     return !col || getline('.')[col - 1]  =~ '\s'
  endfunction"}}}

  " <C-h>, <BS>: close popup and delete backword char.
  inoremap <expr><C-h> neocomplcache#smart_close_popup()."\<C-h>"
  inoremap <expr><BS> neocomplcache#smart_close_popup()."\<C-h>"
  inoremap <expr><C-y>  neocomplcache#close_popup()
  inoremap <expr><C-e>  neocomplcache#cancel_popup()

  " Dont AutoComplPop like behavior.
  let g:neocomplcache_enable_auto_select = 0
  let g:neocomplcache_disable_auto_complete = 1

  set ofu=syntaxcomplete#Complete

  " Enable heavy omni completion.
  if !exists('g:neocomplcache_omni_patterns')
    let g:neocomplcache_omni_patterns = {}
  endif
  let g:neocomplcache_omni_patterns.ruby = '[^. *\t]\.\w*\|\h\w*::'
  let g:neocomplcache_omni_patterns.php = '[^. \t]->\h\w*\|\h\w*::'
  let g:neocomplcache_omni_patterns.c = '\%(\.\|->\)\h\w*'
  let g:neocomplcache_omni_patterns.cpp = '\h\w*\%(\.\|->\)\h\w*\|\h\w*::'

  " Autocompletion Menu Settings
  set completeopt=longest,menuone
  inoremap <expr> <CR> pumvisible() ? "\<C-y>" : "\<C-g>u\<CR>"

  inoremap <expr> <C-n> pumvisible() ? '<C-n>' :
    \ '<C-n><C-r>=pumvisible() ? "\<lt>Down>" : ""<CR>'

  inoremap <expr> <M-,> pumvisible() ? '<C-n>' :
    \ '<C-x><C-o><C-n><C-p><C-r>=pumvisible() ? "\<lt>Down>" : ""<CR>'

  " automatically close autocompletition window
  autocmd CursorMovedI * if pumvisible() == 0|pclose|endif
  autocmd InsertLeave * if pumvisible() == 0|pclose|endif
" }}}
" Whitespace & EndingSpace Highlight {{{
highlight ExtraWhitespace ctermbg=red guibg=red
match ExtraWhitespace /\s\+$/
set list listchars=tab:»·,trail:·,extends:$,nbsp:= 
" }}}

" My autorun hooks {{{
if !exists('s:initialized')
  let s:initialized=1
  let s:cwd = getcwd()
en
" }}}

" seperate viminfo/ctrlp session for screen window {{{
if $STY != ''
set viminfo+=n~/.vim/.viminfo_${STY}.${WINDOW}
let g:ctrlp_cache_dir = "~/.cache/ctrlp_$STY.$WINDOW"
endif
" }}}
" vim:ft=vim:fdm=marker:ff=unix:nowrap:tabstop=4:shiftwidth=4:softtabstop=4:smarttab:shiftround:expandtab
"
" multi cursor use {{{
let g:multi_cursor_use_default_mapping=0

" Default mapping
" let g:multi_cursor_start_word_key      = '<C-n>'
let g:multi_cursor_start_word_key      = '<C-m>'
" let g:multi_cursor_select_all_word_key = '<A-n>'
" let g:multi_cursor_start_key           = 'g<C-n>'
" let g:multi_cursor_select_all_key      = 'g<A-n>'

" let g:multi_cursor_next_key            = '<C-n>'
let g:multi_cursor_next_key            = '<C-m>'

" let g:multi_cursor_prev_key            = '<C-p>'
let g:multi_cursor_prev_key            = '<C-,>'

" let g:multi_cursor_skip_key            = '<C-x>'
let g:multi_cursor_quit_key            = '<Esc>'
" }}}

" YCM Go to definition
let g:ycm_autoclose_preview_window_after_completion=1
map <leader>g  :YcmCompleter GoToDefinitionElseDeclaration<CR>
