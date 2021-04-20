#!/bin/bash

#c_black=$(tput setaf 0)
#c_red=$(tput setaf 1)
#c_green=$(tput setaf 2)
#c_yellow=$(tput setaf 3)
#c_blue=$(tput setaf 4)
#c_magenta=$(tput setaf 5)
#c_cyan=$(tput setaf 6)
#c_white=$(tput setaf 7)
#c_off="$(tput setaf 9)"

c_default="\e[39m"
c_black="\e[30m"
c_red="\e[31m"
c_green="\e[32m"
c_yellow="\e[33m"
c_blue="\e[34m"
c_magenta="\e[35m"
c_cyan="\e[36m"
c_lgray="\e[37m"
c_dgray="\e[m90"
c_lred="\e[91m"
c_lgreen="\e[92m"
c_lyellow="\e[93m"
c_lblue="\e[94m"
c_lmagenta="\e[95m"
c_lcyan="\e[96m"
c_white="\e[97m"
c_off="\e[0m"

t_bold=$(tput bold)
t_underline=$(tput smul)
t_underline_off=$(tput rmul)
t_rev=$(tput rev)
t_blink=$(tput blink)
t_invis=$(tput invis)
t_standout=$(tput smso)
t_standout_off=$(tput rmso)
t_off=$(tput sgr0)

function echoerr
{
	echo "$1" >&2
}

function printerr
{
	printf "${c_red}${t_bold}Error:${t_off} ${c_red}$1${c_off}\n" >&2
}
