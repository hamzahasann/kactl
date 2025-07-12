set autoread nu rnu ts=2 sts=2 sw=2 et si nowrap
set nohlsearch incsearch so=8 scl=yes isf+=@-@
autocmd FocusGained,BufEnter * checktime
let mapleader=" "
" Key mappings
nnoremap <leader>pv :Ex<CR> | vnoremap J :m '>+1<CR>gv=gv 
vnoremap K :m '<-2<CR>gv=gv
" Improved join and navigation
nnoremap J mzJ`z | nnoremap <C-d> <C-d>zz 
nnoremap <C-u> <C-u>zz | nnoremap n nzzzv | nnoremap N Nzzzv
" Greatest remap ever
xnoremap <leader>p "_dP
" Next greatest remap ever
nnoremap <leader>y "+y | vnoremap <leader>y "+y 
nnoremap <leader>Y "+Y
" Pane navigation using Ctrl + hjkl
nnoremap <C-j> <C-w>j | nnoremap <C-k> <C-w>k 
nnoremap <C-h> <C-w>h | nnoremap <C-l> <C-w>l

function! CARQ()
  w | let f=expand('%:p') 
  silent execute '!g++ -Wshadow -DKRAKAR -o a.out ' . f . ' 2>&1 | tee /tmp/quickfix.log'
  cfile /tmp/quickfix.log 
  if getqflist({'size':0}).size > 0 
  copen | else | execute '!./a.out 2> debug.txt' | endif
endfunction
nnoremap <leader>rc :silent! call CARQ() \| redraw!<CR>
syntax on
filetype indent on
colorscheme desert
