# Wrong color in tmux session

- add to .tmux.conf
```sh
set -g default-terminal "xterm-256color"
set -ga terminal-overrides ",*256col*:Tc"
```
