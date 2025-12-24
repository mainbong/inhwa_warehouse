# Modern tmux Configuration

> Updated 2024 - tmux 3.4+ compatible
> Optimized for Neovim + Cloud Development

## ✨ Features

- **TPM (Tmux Plugin Manager)** - 9개 강력한 플러그인
- **Session Persistence** - 재부팅해도 세션 유지 (자동 저장/복원)
- **System Clipboard Integration** - 마우스/키보드 복사 모두 지원
- **Tokyo Night Theme** - Neovim과 완벽한 조화
- **Vim-style Navigation** - h/j/k/l로 패널 이동
- **True Color Support** - Neovim 호환
- **Smart Search** - 파일/URL/IP 빠른 검색

## 📦 Installation

### Quick Start

```bash
# 1. tmux 설치
brew install tmux  # macOS
# 또는
sudo apt install tmux  # Ubuntu

# 2. 설정 복사
git clone git@github.com:mainbong/inhwa_warehouse.git
cd inhwa_warehouse
cp tmux/.tmux.conf ~/

# 3. TPM 설치
git clone https://github.com/tmux-plugins/tpm ~/.tmux/plugins/tpm

# 4. tmux 실행
tmux

# 5. 플러그인 설치
# tmux 안에서: Ctrl+a 그리고 Shift+i
```

### 설정 확인

```bash
# tmux 버전 확인 (3.0+ 권장)
tmux -V

# 설정 리로드
# tmux 안에서: Ctrl+a r
```

## 🎮 Key Bindings

### Basic Navigation

| 키 | 기능 | 설명 |
|---|------|------|
| `C-a` | **Prefix** | 모든 tmux 명령의 시작 |
| `C-a r` | **설정 리로드** | .tmux.conf 다시 로드 |
| `C-a ?` | **단축키 목록** | 모든 키바인딩 표시 |
| `C-a d` | **Detach** | 세션에서 나가기 (세션은 유지) |

### Window (탭) 관리

| 키 | 기능 |
|---|------|
| `C-a c` | 새 창 생성 (현재 경로) |
| `C-a ,` | 창 이름 변경 |
| `C-a n` | 다음 창 |
| `C-a p` | 이전 창 |
| `C-a 0-9` | 0-9번 창으로 이동 |
| `Alt+1-9` | **빠른 창 전환** (prefix 없이!) |
| `C-a &` | 창 닫기 (확인 후) |
| `C-a w` | 창 목록 표시 |

### Pane (패널) 관리

| 키 | 기능 |
|---|------|
| `C-a \|` | 수평 분할 (좌우) |
| `C-a -` | 수직 분할 (상하) |
| `C-a h/j/k/l` | **Vim 스타일 패널 이동** |
| `C-a H/J/K/L` | 패널 크기 조정 (5칸씩) |
| `C-a x` | 패널 닫기 |
| `C-a z` | 패널 최대화/복원 토글 |
| `C-a {` | 패널 왼쪽으로 이동 |
| `C-a }` | 패널 오른쪽으로 이동 |
| `C-a q` | 패널 번호 표시 |
| `C-a Space` | 패널 레이아웃 변경 |

### Copy Mode (복사 모드)

| 키 | 기능 |
|---|------|
| `C-a [` | 복사 모드 진입 |
| `v` | 선택 시작 (Vi 모드) |
| `V` | 라인 선택 |
| `C-v` | 블록 선택 |
| `y` | 복사 및 종료 (자동으로 시스템 클립보드에!) |
| `C-a p` | 붙여넣기 |
| `q` / `Esc` | 복사 모드 종료 |
| `/` | 검색 |
| `n` | 다음 검색 결과 |
| `N` | 이전 검색 결과 |

### Session 관리

| 키 | 기능 |
|---|------|
| `C-a C-c` | 새 세션 생성 |
| `C-a C-f` | 세션 검색 |
| `C-a s` | 세션 목록 |
| `C-a $` | 세션 이름 변경 |

```bash
# 명령줄에서:
tmux new -s mysession        # 이름 지정하여 생성
tmux ls                      # 세션 목록
tmux attach -t mysession     # 세션 접속
tmux kill-session -t mysession  # 세션 종료
```

## 🔌 Plugins

### 1. tmux-resurrect - 세션 저장/복원 ⭐⭐⭐⭐⭐

**가장 강력한 기능!**

| 키 | 기능 |
|---|------|
| `C-a C-s` | **세션 저장** |
| `C-a C-r` | **세션 복원** |

**저장되는 것:**
- ✅ 모든 창과 패널
- ✅ 패널 레이아웃
- ✅ 작업 디렉토리
- ✅ 실행 중인 프로그램
- ✅ **Neovim 세션** (열려있던 파일까지!)
- ✅ **패널 내용** (스크롤백 포함)

**사용 예시:**
```bash
# 금요일 퇴근 전
C-a C-s  # 모든 작업 저장

# 컴퓨터 재부팅...

# 월요일 출근 후
tmux
C-a C-r  # 금요일 상태 그대로 복원!
```

### 2. tmux-continuum - 자동 저장/복원 ⭐⭐⭐⭐⭐

**설정:**
- 15분마다 자동 저장
- tmux 시작 시 자동 복원

**혜택:**
- 수동 저장 불필요
- 재부팅해도 세션 자동 복원
- 네트워크 끊김에도 안전

### 3. tmux-yank - 클립보드 통합 ⭐⭐⭐⭐

**기능:**
- 복사 시 자동으로 시스템 클립보드로
- 마우스 선택만 해도 복사됨
- macOS, Linux 모두 지원

**사용:**
```bash
C-a [    # 복사 모드
v        # 선택 시작
y        # 복사 → 자동으로 Cmd+V로 붙여넣기 가능!
```

### 4. tmux-copycat - 강력한 검색 ⭐⭐⭐⭐

| 키 | 검색 대상 |
|---|----------|
| `C-a C-f` | **파일 경로** |
| `C-a C-u` | **URL** |
| `C-a C-i` | **IP 주소** |
| `C-a C-g` | Git status 파일 |
| `C-a C-h` | SHA 해시 |
| `C-a C-d` | 숫자 |

**검색 후:**
- `n` - 다음 결과
- `N` - 이전 결과
- `Enter` - 복사 모드로 전환

**사용 예시:**
```bash
# 로그에서 에러 파일 찾기
tail -f app.log
# Error in /app/src/main.go:42

C-a C-f  # 파일 경로 검색
n        # /app/src/main.go:42 하이라이트
Enter    # 복사 모드
v, y     # 복사
```

### 5. tmux-open - 파일/URL 열기 ⭐⭐⭐⭐

**복사 모드에서:**
- `o` - 선택한 항목 열기
  - 파일 경로 → `$EDITOR` (nvim)로 열기
  - URL → 브라우저로 열기
- `C-o` - `$EDITOR`로 강제 열기

**사용 예시:**
```bash
# 로그에서 URL 찾기
C-a C-u           # URL 검색
n                 # https://api.example.com으로 이동
o                 # 브라우저에서 바로 열림!

# 파일 경로
C-a C-f           # 파일 검색
n                 # /path/to/config.yaml
o                 # nvim으로 바로 열림!
```

### 6. tmux-prefix-highlight - Prefix 시각화 ⭐⭐⭐

**기능:**
- `C-a` 누르면 상태바에 `[PREFIX]` 표시
- 복사 모드일 때 `[COPY]` 표시
- Prefix 눌렀는지 시각적으로 확인 가능

### 7. tmux-pain-control - 향상된 패널 관리 ⭐⭐⭐

**추가 단축키:**
- `C-a \` - 전체 화면 수평 분할
- 패널 크기 조정 개선

### 8. tmux-tokyo-night - 아름다운 테마 ⭐⭐⭐⭐⭐

**특징:**
- Neovim Tokyo Night 테마와 완벽 조화
- 현대적이고 깔끔한 디자인
- True color 지원

### 9. tmux-sensible - 기본 설정 개선 ⭐⭐⭐⭐

**자동 최적화:**
- 이스케이프 딜레이 최소화
- 히스토리 크기 증가
- UTF-8 자동 설정
- 포커스 이벤트 활성화

## 🚀 실전 워크플로우

### 워크플로우 1: 클라우드 서버 개발

```bash
# 서버 접속
ssh my-cloud-server

# tmux 세션 생성 (없으면) 또는 재접속
tmux new -s dev || tmux attach -t dev

# 패널 구성
C-a |        # 좌: 코드 편집
C-a -        # 우상: 서버 실행
C-a l        # 우측 패널로 이동
C-a -        # 우하: 로그 모니터링

# 작업 중...
# 네트워크 끊김!

# 재접속
ssh my-cloud-server
tmux attach -t dev
# → 모든 패널, 프로세스 그대로 유지!
```

### 워크플로우 2: 로컬 개발

```bash
# 프로젝트별 세션
tmux new -s myproject

# 레이아웃
C-a |        # 좌: nvim
C-a l
C-a -        # 우상: git status 확인
C-a -        # 우하: 테스트 실행

# 다른 프로젝트 작업
C-a d        # detach (세션 유지)

tmux new -s another-project
# 작업...

# 원래 프로젝트로 복귀
tmux attach -t myproject
```

### 워크플로우 3: 디버깅

```bash
# 에러 로그 분석
tail -f error.log

# 에러 메시지에서 파일 찾기
# Error in /app/handlers/user.go:156

C-a C-f      # 파일 경로 검색
n            # /app/handlers/user.go:156로 이동
o            # nvim으로 바로 열기!

# API URL 테스트
C-a C-u      # URL 검색
n            # https://api.example.com/users
o            # 브라우저에서 바로 확인!
```

### 워크플로우 4: 세션 템플릿

```bash
# 개발 환경 템플릿 만들기
tmux new -s template

# 창 구성
C-a c        # 창 1: Editor
C-a c        # 창 2: Server
C-a c        # 창 3: Database
C-a c        # 창 4: Logs

# 각 창에서 필요한 명령 실행
# 창 1:
nvim

# 창 2:
npm run dev

# 창 3:
docker exec -it db psql

# 창 4:
tail -f logs/app.log

# 세션 저장
C-a C-s

# 다음에 사용
C-a C-r      # 템플릿 복원!
```

## 🎨 Customization

### 테마 변경

Tokyo Night 말고 다른 테마 원하면:

```bash
# .tmux.conf에서 변경
set -g @plugin 'fabioluciano/tmux-tokyo-night'

# 다른 인기 테마들:
# set -g @plugin 'catppuccin/tmux'
# set -g @plugin 'dracula/tmux'
# set -g @plugin 'nordtheme/tmux'
```

### Prefix 키 변경

```bash
# C-a 대신 C-b로 (기본값)
# .tmux.conf 수정:
set-option -g prefix C-b
bind-key C-b send-prefix
```

### 상태바 커스터마이징

```bash
# .tmux.conf에서:
set -g status-right "#[fg=cyan]#H #[fg=white]%Y-%m-%d %H:%M"

# 사용 가능한 변수:
# #H - 호스트명
# #S - 세션 이름
# #I - 창 번호
# #W - 창 이름
# #P - 패널 번호
```

## 🐛 Troubleshooting

### 색상이 제대로 안 보임

```bash
# .tmux.conf에 추가:
set -g default-terminal "tmux-256color"
set -ga terminal-overrides ",*256col*:Tc"

# 터미널 확인:
echo $TERM  # 'tmux-256color' 또는 'xterm-256color' 이어야 함
```

### 마우스가 안 됨

```bash
# 마우스 활성화 확인:
set -g mouse on

# tmux에서:
C-a r  # 설정 리로드
```

### 플러그인이 로드 안 됨

```bash
# TPM 재설치:
rm -rf ~/.tmux/plugins/tpm
git clone https://github.com/tmux-plugins/tpm ~/.tmux/plugins/tpm

# tmux 재시작:
tmux kill-server
tmux

# 플러그인 설치:
C-a I  # (capital I)
```

### Neovim에서 Esc 딜레이

```bash
# .tmux.conf에 확인:
set -sg escape-time 0

# Neovim에서도 설정:
# init.lua에:
vim.opt.timeoutlen = 500
vim.opt.ttimeoutlen = 0
```

### 세션 복원이 안 됨

```bash
# 저장 디렉토리 확인:
ls ~/.tmux/resurrect/

# 수동 복원:
~/.tmux/plugins/tmux-resurrect/scripts/restore.sh

# 로그 확인:
tmux show-messages
```

## 📚 Advanced Tips

### Tip 1: 세션 공유 (Pair Programming)

```bash
# 서버에서:
tmux new -s pair

# 다른 사용자:
ssh user@server
tmux attach -t pair

# → 같은 화면 공유!
```

### Tip 2: 스크립트로 세션 생성

```bash
#!/bin/bash
# dev-session.sh

SESSION="dev"

tmux new-session -d -s $SESSION

# 창 1: Editor
tmux rename-window -t $SESSION:1 'editor'
tmux send-keys -t $SESSION:1 'cd ~/project && nvim' C-m

# 창 2: Server
tmux new-window -t $SESSION:2 -n 'server'
tmux send-keys -t $SESSION:2 'npm run dev' C-m

# 창 3: Logs
tmux new-window -t $SESSION:3 -n 'logs'
tmux send-keys -t $SESSION:3 'tail -f logs/app.log' C-m

# 접속
tmux attach -t $SESSION
```

### Tip 3: 창 동기화 (모든 패널에 같은 명령)

```bash
C-a :  # 명령 모드
setw synchronize-panes on

# 이제 모든 패널에 동시에 타이핑됨
# 여러 서버에 같은 명령 실행할 때 유용!

# 해제:
setw synchronize-panes off
```

### Tip 4: 복사 모드에서 Vim 키바인딩 전체 활용

```bash
# 복사 모드에서:
h, j, k, l    # 이동
w, b          # 단어 단위 이동
0, $          # 행 시작/끝
gg, G         # 파일 시작/끝
C-u, C-d      # 페이지 up/down
/             # 검색
n, N          # 다음/이전 검색
```

### Tip 5: 상태바에 Git 브랜치 표시

```bash
# .tmux.conf에 추가:
set -g status-right '#(cd #{pane_current_path}; git rev-parse --abbrev-ref HEAD 2>/dev/null) %Y-%m-%d %H:%M'
```

## 📖 Resources

- [tmux GitHub](https://github.com/tmux/tmux)
- [TPM GitHub](https://github.com/tmux-plugins/tpm)
- [tmux Cheat Sheet](https://tmuxcheatsheet.com/)
- [Awesome tmux](https://github.com/rothgar/awesome-tmux)

## 🎓 Learning Path

1. **기초 (1주)**
   - Prefix 키 익히기
   - 창/패널 생성, 이동
   - Detach/Attach

2. **중급 (2주)**
   - 복사 모드 마스터
   - 세션 저장/복원
   - 플러그인 활용

3. **고급 (1개월)**
   - 커스텀 레이아웃
   - 스크립트 자동화
   - 페어 프로그래밍

## ⌨️ Quick Reference Card

```
┌─────────────────────────────────────────────────────┐
│ tmux Quick Reference                                │
├─────────────────────────────────────────────────────┤
│ Prefix: C-a                                         │
│                                                     │
│ Session:                                            │
│   C-a d     Detach        C-a C-s    Save          │
│   C-a $     Rename        C-a C-r    Restore       │
│                                                     │
│ Window:                                             │
│   C-a c     New           Alt+1-9    Quick switch  │
│   C-a ,     Rename        C-a &      Close         │
│                                                     │
│ Pane:                                               │
│   C-a |     Split H       C-a h/j/k/l  Navigate   │
│   C-a -     Split V       C-a H/J/K/L  Resize     │
│   C-a x     Close         C-a z       Zoom        │
│                                                     │
│ Copy:                                               │
│   C-a [     Enter         v          Select       │
│   y         Copy          C-a p      Paste        │
│                                                     │
│ Search:                                             │
│   C-a C-f   Files         C-a C-u    URLs         │
│   C-a C-i   IPs           n/N        Next/Prev    │
│                                                     │
│ Plugin:                                             │
│   C-a I     Install       C-a U      Update       │
└─────────────────────────────────────────────────────┘
```

## 🤝 Contributing

개인 설정이지만, 자유롭게 Fork하여 사용하세요!

## 📝 License

MIT

---

**Last Updated:** 2024-12-24
**tmux Version:** 3.4+
**Theme:** Tokyo Night
