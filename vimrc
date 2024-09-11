" - UI/UX
syntax on         " enable syntax hilighting
set ruler         " show line:column numbers
set showmatch     " highlight matching parens, braces, and brackets
set smarttab      " autoindent

" - Tabs
set tabstop=4     " set tab width to 4
set expandtab     " use spaces instead of tab character
set shiftwidth=4  "

" - C++ Compilation and running
let cpp_compiler_args = '' " Initalize variable, don't remove
"let cpp_compiler_args = cpp_compiler_args . '-w' " No inhibit all warnings, not reccomended
"let cpp_compiler_args = cpp_compiler_args . '-Werror' " Convert warnings to errors (doesn't compile if any warnings exist)
let cpp_compiler_args = cpp_compiler_args . '-Wall' " All common warnings, reccomended
"let cpp_compiler_args = cpp_compiler_args . '-Wextra' " Some more warnings that are not included in all
nmap <buffer> <f5> :w<CR>:exec '!clear; g++' cpp_compiler_args shellescape(@%, 1) '-o' shellescape(@%, 1) . '.out; if [ $? -eq 0 ]; then; ./' . shellescape(@%, 1) . '.out' '; fi'<CR>
