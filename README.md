# simple_shell

Hello, welcome to our second group project, we're replicating the shell Linux

### version 1.0

## Introduction to the project

Bash is an sh-compatible command language interpreter that executes commands read from the standard input or from a file.

## Evironment
- Language: C
- Editor: VIM 8.1.2269
- Compiler: gcc 9.3.0
- Wall -Werror -Wextra -pedantic -std=gnu89
- Style guidelines: [Betty style](https://github.com/holbertonschool/Betty/wiki)

## Built-in Commands

| Command    | Output          |
|------------|-----------------|
| `env`      | print env       |
| `exit`     | exit shell      |

## Install
To install execute in terminal
`git clone https://github.com/brunonra-dev/simple_shell`

## Compilation

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## Valgrind debug

`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -g *.c -o hsh`

`valgrind --tool=memcheck --leak-check=yes --track-origins=yes --show-leak-kinds=all -s ./hsh`

## Examples:

Input: 
`$ ls`

Output:

`AUTHORS     _putchar.c  a.out       commandex.c        freeisa.c  man_1_simple_shell  subprocess.c
README.md   _strcmp.c   built-in.c  error.c            llpath.c   prueba
_addnode.c  _strdup.c   check.c     flowchartnew2.png  main.h     shell.c`

Input:
`$ /bin/ls`

Output:

`AUTHORS     _putchar.c  a.out       commandex.c        freeisa.c  man_1_simple_shell  subprocess.c
README.md   _strcmp.c   built-in.c  error.c            llpath.c   prueba
_addnode.c  _strdup.c   check.c     flowchartnew2.png  main.h     shell.c`

Input:
`$ env`

Output:

`HOSTNAME=83f864a25fd0
LANGUAGE=en_US:en
PWD=/root/simple_shell
TZ=America/Los_Angeles
HOME=/root
LANG=en_US.UTF-8
LS_COLORS=rs=0:di=01;34:ln=01;36:mh=00:pi=40;33:so=01;35:do=01;35:bd=40;33;01:cd=40;33;01:or=40;31;01:mi=00:su=37;41:sg=30;43:ca=30;41:tw=30;42:ow=34;42:st=37;44:ex=01;32:*.tar=01;31:*.tgz=01;31:*.arc=01;31:*.arj=01;31:*.taz=01;31:*.lha=01;31:*.lz4=01;31:*.lzh=01;31:*.lzma=01;31:*.tlz=01;31:*.txz=01;31:*.tzo=01;31:*.t7z=01;31:*.zip=01;31:*.z=01;31:*.dz=01;31:*.gz=01;31:*.lrz=01;31:*.lz=01;31:*.lzo=01;31:*.xz=01;31:*.zst=01;31:*.tzst=01;31:*.bz2=01;31:*.bz=01;31:*.tbz=01;31:*.tbz2=01;31:*.tz=01;31:*.deb=01;31:*.rpm=01;31:*.jar=01;31:*.war=01;31:*.ear=01;31:*.sar=01;31:*.rar=01;31:*.alz=01;31:*.ace=01;31:*.zoo=01;31:*.cpio=01;31:*.7z=01;31:*.rz=01;31:*.cab=01;31:*.wim=01;31:*.swm=01;31:*.dwm=01;31:*.esd=01;31:*.jpg=01;35:*.jpeg=01;35:*.mjpg=01;35:*.mjpeg=01;35:*.gif=01;35:*.bmp=01;35:*.pbm=01;35:*.pgm=01;35:*.ppm=01;35:*.tga=01;35:*.xbm=01;35:*.xpm=01;35:*.tif=01;35:*.tiff=01;35:*.png=01;35:*.svg=01;35:*.svgz=01;35:*.mng=01;35:*.pcx=01;35:*.mov=01;35:*.mpg=01;35:*.mpeg=01;35:*.m2v=01;35:*.mkv=01;35:*.webm=01;35:*.ogm=01;35:*.mp4=01;35:*.m4v=01;35:*.mp4v=01;35:*.vob=01;35:*.qt=01;35:*.nuv=01;35:*.wmv=01;35:*.asf=01;35:*.rm=01;35:*.rmvb=01;35:*.flc=01;35:*.avi=01;35:*.fli=01;35:*.flv=01;35:*.gl=01;35:*.dl=01;35:*.xcf=01;35:*.xwd=01;35:*.yuv=01;35:*.cgm=01;35:*.emf=01;35:*.ogv=01;35:*.ogx=01;35:*.aac=00;36:*.au=00;36:*.flac=00;36:*.m4a=00;36:*.mid=00;36:*.midi=00;36:*.mka=00;36:*.mp3=00;36:*.mpc=00;36:*.ogg=00;36:*.ra=00;36:*.wav=00;36:*.oga=00;36:*.opus=00;36:*.spx=00;36:*.xspf=00;36:
LESSCLOSE=/usr/bin/lesspipe %s %s
TERM=xterm
LESSOPEN=| /usr/bin/lesspipe %s
SHLVL=1
LC_ALL=en_US.UTF-8
PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
_=./a.out
OLDPWD=/root`

# Flowchart

![Flowchart](https://raw.githubusercontent.com/brunonra-dev/simple_shell/main/flowchartnew2.png)

Created by [Bruno Rodríguez](https://github.com/brunonra-dev/) & [Matias López](https://github.com/Matilop15)
