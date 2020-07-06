export alias ctags="`brew --prefix`/bin/ctags"

export GRADLE_HOME='/usr/local/opt/gradle/libexec'
export JAVA_HOME=$(/usr/libexec/java_home -v 1.8)

export PATH=${PATH}:${HOME}/bin:${GRADLE_HOME}/bin
export PATH=${PATH}:/Applications/MySQLWorkbench.app/Contents/MacOS
export TERM=xterm-256color
export CLICOLOR=1
export LSCOLORS=GxFxCxDxBxegedabagaced
export GREP_OPTIONS='--color=auto'
alias ls='ls -GFh'
alias ll='ls -al'
alias python='python3'
alias pip='pip3'

# 도커 이미지, 컨테이너 상태보기
alias dockerstate='docker images; echo "\n"; docker ps -a'

# 도커 통검 접속
alias dockerusfpc='docker exec -u hanadmin -e COLUMNS=$(tput cols) -e LINES=$(tput lines) -it usfpc /bin/bash'
alias dockerusfmo='docker exec -u hanadmin -e COLUMNS=$(tput cols) -e LINES=$(tput lines) -it usfmo /bin/bash'

# 도커 통검 중지
alias dockerstopusfpc='docker stop usfpc'
alias dockerstopusfmo='docker stop usfmo'

# 도커 통검 시작
alias dockerstartusfpc='docker start usfpc'
alias dockerstartusfmo='docker start usfmo'

# 도커 통검 컨테이너 (중지후) 삭제
alias dockerrmusfpc='dockerstopusfpc; docker rm usfpc'
alias dockerrmusfmo='dockerstopusfmo; docker rm usfmo'

# 도커 통검 삭제
alias dockerdestroyusfpc='docker stop usfpc; docker rm usfpc; docker rmi -f idock.daumkakao.io/usf-docker/pc_tot_search'
alias dockerdestroyusfmo='docker stop usfmo; docker rm usfmo; docker rmi -f idock.daumkakao.io/usf-docker/mo_tot_search'
alias dockerdestroyall='dockerdestroyusfpc; dockerdestroyusfmo; docker rmi -f $(docker images -q)'

# 도커 이미지 받기
alias dockerpullusfpc='docker pull idock.daumkakao.io/usf-docker/pc_tot_search'
alias dockerpullusfmo='docker pull idock.daumkakao.io/usf-docker/mo_tot_search'

# 도커 통검 컨테이너 실행
alias dockerrunusfpc='docker run --name usfpc --hostname usfpc -p 10010:80 -dit --cap-add SYS_PTRACE idock.daumkakao.io/usf-docker/pc_tot_search && docker ps -a'
alias dockerrunusfmo='docker run --name usfmo --hostname usfmo -p 10020:80 -dit --cap-add SYS_PTRACE idock.daumkakao.io/usf-docker/mo_tot_search && docker ps -a'

# 개발 통검 도커 사용시
alias dockerdestroyusfpcdev='docker stop usfpc; docker rm usfpc; docker rmi -f idock.daumkakao.io/usf-docker/pc_tot_search:dev'
alias dockerdestroyusfmodev='docker stop usfmo; docker rm usfmo; docker rmi -f idock.daumkakao.io/usf-docker/mo_tot_search:dev'
alias dockerpullusfpcdev='docker pull idock.daumkakao.io/usf-docker/pc_tot_search:dev'
alias dockerpullusfmodev='docker pull idock.daumkakao.io/usf-docker/mo_tot_search:dev'
alias dockerrunusfpc='docker run --name usfpc --hostname usfpc -p 10010:80 -dit --cap-add SYS_PTRACE idock.daumkakao.io/usf-docker/pc_tot_search:dev && docker ps -a'
alias dockerrunusfmo='docker run --name usfmo --hostname usfmo -p 10020:80 -dit --cap-add SYS_PTRACE idock.daumkakao.io/usf-docker/mo_tot_search:dev && docker ps -a'

alias dockerpcupdatedata='docker exec -u hanadmin -it usfpc bash -c "rm -rf /daum/data/tmp && mkdir -p /daum/data/tmp && /daum/data/download_data.py -d pc -z test -t /daum/data/tmp && rsync -rlpgoDc --delete /daum/data/tmp/ /daum/data/pc_tot_search"'
alias dockermoupdatedata='docker exec -u hanadmin -it usfmo bash -c "rm -rf /daum/data/tmp && mkdir -p /daum/data/tmp && /daum/data/download_data.py -d mo -z test -t /daum/data/tmp && rsync -rlpgoDc --delete /daum/data/tmp/ /daum/data/mo_tot_search"'


## oracle home
export ORACLE_HOME=/opt/oracle/instantclient
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ORACLE_HOME
export OCI_LIB_DIR=/opt/oracle/instantclient
export OCI_INC_DIR=/opt/oracle/instantclient/sdk/include

#THIS MUST BE AT THE END OF THE FILE FOR SDKMAN TO WORK!!!
export SDKMAN_DIR="/Users/kakao/.sdkman"
[[ -s "/Users/kakao/.sdkman/bin/sdkman-init.sh" ]] && source "/Users/kakao/.sdkman/bin/sdkman-init.sh"
export JAVA_HOME=`/usr/libexec/java_home -v1.8`
export PATH="$JAVA_HOME/bin:$PATH"
#source ~/.savanna-hadoop-env
#source ~/.doopey-env

# Android Development
export PATH="/Users/kakao/Library/Android/sdk/platform-tools:$PATH"

export ANDROID_HOME="/Users/kakao/Library/Android/sdk"

# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/Users/kakao/anaconda3/bin/conda' 'shell.bash' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/Users/kakao/anaconda3/etc/profile.d/conda.sh" ]; then
        . "/Users/kakao/anaconda3/etc/profile.d/conda.sh"
    else
        export PATH="/Users/kakao/anaconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<<

# flutter setting
export PATH="$PATH:/Users/kakao/flutter/bin"
