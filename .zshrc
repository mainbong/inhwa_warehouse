# If you come from bash you might have to change your $PATH.
# export PATH=$HOME/bin:/usr/local/bin:$PATH

# Path to your oh-my-zsh installation.
export ZSH="/Users/sher.lock/.oh-my-zsh"

# Set name of the theme to load --- if set to "random", it will
# load a random theme each time oh-my-zsh is loaded, in which case,
# to know which specific one was loaded, run: echo $RANDOM_THEME
# See https://github.com/robbyrussell/oh-my-zsh/wiki/Themes
ZSH_THEME="agnoster"

# Set list of themes to pick from when loading at random
# Setting this variable when ZSH_THEME=random will cause zsh to load
# a theme from this variable instead of looking in ~/.oh-my-zsh/themes/
# If set to an empty array, this variable will have no effect.
# ZSH_THEME_RANDOM_CANDIDATES=( "robbyrussell" "agnoster" )

# Uncomment the following line to use case-sensitive completion.
# CASE_SENSITIVE="true"

# Uncomment the following line to use hyphen-insensitive completion.
# Case-sensitive completion must be off. _ and - will be interchangeable.
# HYPHEN_INSENSITIVE="true"

# Uncomment the following line to disable bi-weekly auto-update checks.
# DISABLE_AUTO_UPDATE="true"

# Uncomment the following line to automatically update without prompting.
# DISABLE_UPDATE_PROMPT="true"

# Uncomment the following line to change how often to auto-update (in days).
# export UPDATE_ZSH_DAYS=13

# Uncomment the following line if pasting URLs and other text is messed up.
# DISABLE_MAGIC_FUNCTIONS=true

# Uncomment the following line to disable colors in ls.
# DISABLE_LS_COLORS="true"

# Uncomment the following line to disable auto-setting terminal title.
# DISABLE_AUTO_TITLE="true"

# Uncomment the following line to enable command auto-correction.
# ENABLE_CORRECTION="true"

# Uncomment the following line to display red dots whilst waiting for completion.
# COMPLETION_WAITING_DOTS="true"

# Uncomment the following line if you want to disable marking untracked files
# under VCS as dirty. This makes repository status check for large repositories
# much, much faster.
# DISABLE_UNTRACKED_FILES_DIRTY="true"

# Uncomment the following line if you want to change the command execution time
# stamp shown in the history command output.
# You can set one of the optional three formats:
# "mm/dd/yyyy"|"dd.mm.yyyy"|"yyyy-mm-dd"
# or set a custom format using the strftime function format specifications,
# see 'man strftime' for details.
# HIST_STAMPS="mm/dd/yyyy"

# Would you like to use another custom folder than $ZSH/custom?
# ZSH_CUSTOM=/path/to/new-custom-folder

# Which plugins would you like to load?
# Standard plugins can be found in ~/.oh-my-zsh/plugins/*
# Custom plugins may be added to ~/.oh-my-zsh/custom/plugins/
# Example format: plugins=(rails git textmate ruby lighthouse)
# Add wisely, as too many plugins slow down shell startup.
plugins=(git)

source $ZSH/oh-my-zsh.sh

# User configuration

# export MANPATH="/usr/local/man:$MANPATH"

# You may need to manually set your language environment
# export LANG=en_US.UTF-8

# Preferred editor for local and remote sessions
# if [[ -n $SSH_CONNECTION ]]; then
#   export EDITOR='vim'
# else
#   export EDITOR='mvim'
# fi

# Compilation flags
# export ARCHFLAGS="-arch x86_64"

# Set personal aliases, overriding those provided by oh-my-zsh libs,
# plugins, and themes. Aliases can be placed here, though oh-my-zsh
# users are encouraged to define aliases within the ZSH_CUSTOM folder.
# For a full list of active aliases, run `alias`.
#
# Example aliases
# alias zshconfig="mate ~/.zshrc"
# alias ohmyzsh="mate ~/.oh-my-zsh"

source /usr/local/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh

prompt_context() {
  if [[ "$USER" != "$DEFAULT_USER" || -n "$SSH_CLIENT" ]]; then
    prompt_segment black default "%(!.%{%F{yellow}%}.)$USER"
  fi
}

export alias ctags="`brew --prefix`/bin/ctags"

export GRADLE_HOME='/usr/local/opt/gradle/libexec'
export JAVA_HOME=$(/usr/libexec/java_home -v 1.11)
export PATH=${PATH}:${HOME}/bin:${GRADLE_HOME}/bin
export PATH=${PATH}:/Applications/MySQLWorkbench.app/Contents/MacOS

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
export SDKMAN_DIR="/Users/sher.lock/.sdkman"
[[ -s "/Users/sher.lock/.sdkman/bin/sdkman-init.sh" ]] && source "/Users/sher.lock/.sdkman/bin/sdkman-init.sh"
export JAVA_HOME=`/usr/libexec/java_home -v1.11`
export MAVEN_HOME="/Users/sher.lock/bin/apache-maven-3.6.3"

export PATH="$MAVEN_HOME/bin:$JAVA_HOME/bin:$PATH"

#source ~/.savanna-hadoop-env
#source ~/.doopey-env

# Android Development
export PATH="/Users/sher.lock/Library/Android/sdk/platform-tools:$PATH"

export ANDROID_HOME="/Users/sher.lock/Library/Android/sdk"

# Kafka
export KAFKA_HOME="/Users/sher.lock/bin/kafka_2.13-2.8.0"
export PATH="$KAFKA_HOME/bin:$PATH"


# >>> conda initialize >>>
# !! Contents within this block are managed by 'conda init' !!
__conda_setup="$('/Users/sher.lock/anaconda3/bin/conda' 'shell.bash' 'hook' 2> /dev/null)"
if [ $? -eq 0 ]; then
    eval "$__conda_setup"
else
    if [ -f "/Users/sher.lock/anaconda3/etc/profile.d/conda.sh" ]; then
        . "/Users/sher.lock/anaconda3/etc/profile.d/conda.sh"
    else
        export PATH="/Users/sher.lock/anaconda3/bin:$PATH"
    fi
fi
unset __conda_setup
# <<< conda initialize <<

alias python=python3

alias k="kubectl"
alias d="dkosctl"
alias kc="kubectx"
alias kw="watch -n 1 kubectl get pods -o wide --all-namespaces"
alias kpw="watch -n 1 kubectl get pods -o wide"
alias kpwa="watch -n 1 kubectl get pods -o wide -n scdf-apps"
alias kd="kubectl describe pod"
alias kp="kubectl port-forward"
alias kdel="k delete --force --grace-period=0"
alias ks="kubectl get svc --all-namespaces"
alias kclean="kubectl get pod --field-selector=status.phase==Succeeded | awk '{print $1}' | xargs kubectl --namespace=scdf-apps delete pod -o name"
alias kns="kubens scdf"
alias knsa="kubens scdf-apps"
alias krd="k rollout restart deploy "
alias knmd="kubens mongodb"
