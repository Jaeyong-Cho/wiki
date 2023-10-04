# Wrong color in tmux session

- Create a `xterm-24bit.terminfo` file
```sh
xterm-24bit|xterm with 24-bit direct color mode,
   use=xterm-256color,
   sitm=\E[3m,
   ritm=\E[23m,
   setb24=\E[48;2;%p1%{65536}%/%d;%p1%{256}%/%{255}%&%d;%p1%{255}%&%dm,
   setf24=\E[38;2;%p1%{65536}%/%d;%p1%{256}%/%{255}%&%d;%p1%{255}%&%dm,
```
- Execute the following command:
```sh
/usr/bin/tic -x -o ~/.terminfo xterm-24bit.terminfo
```
- set `$TERM` variable
```sh
export TERM=xterm-24bit
```
- add to .tmux.conf
```sh
set -g default-terminal "xterm-24bit"
set -g terminal-overrides ",xterm-24bit:Tc"
```
