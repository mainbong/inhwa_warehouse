# inhwa_warehouse

## Introduction

This is inhwa's vim environment.<br/>
It's light, and smart, easy to use. <br/>

## Getting Started
### Step 1. Setting Envrionment
Let's git clone.
~~~
$ cd ~
$ git clone https://github.com/mainbong/inhwa_warehouse.git
~~~
Now move all files & directories to your home(~/) path.
**Be careful, If you have an environment for vim and tmux,and bashrc.**<br/>
**You have to merge one by one. Don't move all like below.**
~~~
$ cd inhwa_warehouse
$ mv * ~/
# let's source bashrc to use files of 'bin' directly.
$ cd ~/
$ source .bashrc
# unzip .vim.tar.gz to .vim
$ tar xvfz .vim.tar.gz
~~~
And You have to install vim's bundle at first time.
~~~
$ vim
# You would type a command below in vim.
:BundleInstall
# Okay exit vim.
:wq!
~~~
<br/>
### Step 2. Setting Datas for Your Project.
If you have followed upper step very well, you would have an executable file 'prjfiles' in 'bin' folder.<br/>
**prjfiles** is an script to make a list of source codes that you want to analysis. It makes a list of source files to 'cscope.files'.<br/>
Let's make a list.
~~~
$ prjfiles src
~~~
Let's make ctags from a list.
~~~
$ ctags -L cscope.files
~~~
Let's make cscope.out file.
~~~
$ cscope -b
$ ll
drwxrwxr-x  6 inhwa.ma inhwa.ma     4096 12월  6 18:05 ./
drwxrwxr-x  6 inhwa.ma inhwa.ma     4096 12월  5 09:42 ../
-rw-rw-r--  1 inhwa.ma inhwa.ma    87151 12월  5 10:17 cscope.files
-rw-rw-r--  1 inhwa.ma inhwa.ma 10296014 12월  5 10:17 cscope.out
-rw-rw-r--  1 inhwa.ma inhwa.ma        4 12월  5 10:17 .prjdirs
drwxrwxr-x 21 inhwa.ma inhwa.ma     4096 12월  5 09:27 src/
-rw-rw-r--  1 inhwa.ma inhwa.ma  8904057 12월  5 10:17 tags
~~~
Now You can see 4 files added to analysis.<br/>
**cscope.files** for CtrlP vim plugin. <br/>
**cscope.out** for cscope. <br/>
**tags** for ctags. <br/>
**.prjdirs** to record your workdirs. <br/>

## Remember Short Cuts
#### File Open ( CtrlP )
* Press 'Ctrl' + 'p'.<br/>
    If you haven't made 'cscope.files', It would gather all of files of here and subdirs. It may takes long time if there is many files.
    * Typing file name, and press 'Enter' then the file would be opened.
    * Press 'ESC' then file list would be closed.
    * Press 'Ctrl' + 'd' then **Search contents** would be changed from 'File' name search to 'Path'+'File' name search. or vice verse.
    * Press 'Ctrl' + 'r' then **Search algorithm** would be changed from 'Fuzzy' search algorithm to 'Regex' search algorithm. or vice verse.
    * Press 'Ctrl' + 'f' then **List** would be changed from 'File list' to 'Opened file list' to 'MRU file list'.

#### File Explorer ( NERD Tree )
* Press **'Ctrl' + 'n'**.<br/>
    * To refresh it, Press **'Shift' + 'r'**.

#### Ctags
* Press **'Ctrl' + ']'** on a symbol/function that you want to find the tag.<br/>

#### Cscope
* Press **'Ctrl' + '\'** + 'cscope-find command'
    * You can see cscope commands<br/>
~~~
:cs help
cscope commands:
add  : Add a new database             (Usage: add file|dir [pre-path] [flags])
find : Query for a pattern            (Usage: find c|d|e|f|g|i|s|t name)
       c: Find functions calling this function
       d: Find functions called by this function
       e: Find this egrep pattern
       f: Find this file
       g: Find this definition
       i: Find files #including this file
       s: Find this C symbol
       t: Find this text string
help : Show this message              (Usage: help)
kill : Kill a connection              (Usage: kill #)
reset: Reinit all connections         (Usage: reset)
show : Show connections               (Usage: show)
Press ENTER or type command to continue
~~~

* For example, If you want to find a definition for word. Press **'Ctrl' + '\' + 'g'**
* Go next : **']' + 'q'**
* Go prev : **'[' + 'q'**
  
#### Auto Complete ( NeoCompleteCache )
* Press **'TAB'** on the word that you want to complete in 'INSERT' mode.

#### Doxygen comment ( DoxygenToolkit )
* Press **'Ctrl' + 'd'** on the function that you want to add comments.

#### Outline ( TagBar )
* Press **'F9'**

#### Git ( Fugitive )
[Fugitive.vim Guide](http://vimcasts.org/episodes/fugitive-vim---a-complement-to-command-line-git/)<br/>
The result of git blame shows visually.
~~~
:Gblame
~~~

#### Indentation
The master of all commands is
~~~
gg=G
~~~
This indents the entire file!<br/>
And below are some of the simple and elegant commands used to indent lines quickly in Vim or gVim.<br/>
To indent the current line<br/>
~~~
==
~~~
To indent the all the lines below the current line<br/>
~~~
=G
~~~
To indent n lines below the current line<br/>
~~~
n==
~~~
For example, to indent 4 lines below the current line<br/>
~~~
4==
~~~
To indent a block of code, go to one of the braces and use command<br/>
~~~
=%
~~~
These are the simplest, yet powerful commands to indent multiple lines.<br/>

#### Basic short cuts
[Vim Commands Cheet sheet](https://www.fprintf.net/vimCheatSheet.html)<br/>
* How to Exit
    * **:q[uit]** : Quit Vim. This fails when changes have been made.
    * **:q[uit]!** : Quit without writing.
    * **:wq** : Write the current file and exit.
    * **:wq!** : Write the current file and exit always.
    * **:qa** : Exit all panes.
* Editing a File
    * **:e[dit] {file}** : Edit {file}.
* Inserting Text
    * **i** : Insert text before the cursor [count] times.
* Deleting Text
    * **dd** : Delete [count] lines
    * **{Visual}x or {Visual}d** : Delete the highlighted text
* Substituting
    * **:[range]s[ubstitute]/{pattern}/{string}/[c][e][g][p][r][i][I] [count]** : For each line in [range] replace a match of {pattern} with {string}.
* Copying and Moving Text
    * **["x]yy** : Yank [count] lines [into register x]
    * **{Visual}["x]y** : Yank the highlighted text [into register x]
    * **["x]p** : Put the text [from register x] after the cursor [count] times.
    * **["x]P** : Put the text [from register x] before the cursor [count] times.
* Undo/Redo
    * **u** : Undo [count] changes.
    * **CTRL-R** : Redo [count] changes which were undone.
* Moving Around
    * **w** : [count] words forward
    * **b** : [count] words backward
* Marks
    * **m{a-zA-Z}** : Set mark {a-zA-Z} at cursor position (does not move the cursor, this is not a motion command).
    * **'{a-z}** : To the first non-blank character on the line with mark {a-z} (linewise).
* Searching
    * **/{pattern}[/]** : Search forward for the [count]'th occurrence of {pattern}
    * **n** : Repeat the latest "/" or "?" [count] times.
    * **N** : Repeat the latest "/" or "?" [count] times in opposite direction.
* Divide Screen
    * **'Ctrl' + 'w'** : Ready to input a Screen commands. Let's call it **{Screen}**.
    * **{Screen} + 'n'** : Divide screen horizontally
    * **{Screen} + 'v'** : Divide screen vertically
    * **{Screen} + UP/DOWN/RIGHT/LEFT** : Move screen
    * **{Screen} + '='** : Resize all screens to be same size.
