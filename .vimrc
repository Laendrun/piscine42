" Deactivate vi compability
set nocompatible

" Enable type file detection . Vim will be able to try to detect the type of
" file in use.
filetype on

" Turn syntax highlighting on.
syntax on

" Add numbers to each line on the left-hand side.
set number

" Highlight cursor line underneath the cursor horizontally.
set cursorline

" Show the mode you are on on the last line.
set showmode

" Enable mouse navigation
set mouse=a

" Deactivate beeping on error
set visualbell

" Set column 'limit' 
set cc=80

" STATUS LINE -------------------------------------------------------

" Clear status line when vimrc is reloaded.
set statusline=

" Status line left side.
set statusline+=\ %F\ %M

" Use a diider to separate the left side from the right side.
set statusline+=%=

" Status line right side.
set statusline+=\ ascii:\ %b\ row:\ %l\ col:\ %c

" Show the status on the second to last line.
set laststatus=2

" END OF STATUS LINE ------------------------------------------------
