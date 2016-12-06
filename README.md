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

### Step 3. Short Cuts
#### File Open ( CtrlP plugin )
* Press 'Ctrl' + 'p'.<br/>
    If you haven't made 'cscope.files', It would gather all of files of here and subdirs. It may takes long time if there is many files.
    * Typing file name, and press 'Enter' then the file would be opened.
    * Press 'ESC' then file list would be closed.
    * Press 'Ctrl' + 'd' then **Search contents** would be changed from 'File' name search to 'Path'+'File' name search. or vice verse.
    * Press 'Ctrl' + 'r' then **Search algorithm** would be changed from 'Fuzzy' search algorithm to 'Regex' search algorithm. or vice verse.
    * Press 'Ctrl' + 'f' then **List** would be changed from 'File list' to 'Opened file list' to 'MRU file list'.

#### Auto Complete ( NeoCompleteCache )
* Press 'TAB' on the word that you want to complete in 'INSERT' mode.


#### File Explorer ( NERD Tree )
* Press 'Ctrl' + 'n'.<br/>
    * To refresh it, Press 'Shift' + 'r'.

#### Ctags
* Press 'Ctrl' + ']' on a symbol/function that you want to find the tag.<br/>

#### Cscope
* Press 'Ctrl' + '\' + 'cscope command'
    * You can see cscope-find commands<br/>
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
