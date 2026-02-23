# inhwa_warehouse

> **⚠️ 2024년 12월 업데이트: Vim에서 Neovim으로 마이그레이션되었습니다!**

## 🚀 Quick Start

### Neovim 설정 (최신 - 권장)

```bash
# 1. Neovim 설치
brew install neovim  # macOS
# 또는
sudo apt install neovim  # Ubuntu

# 2. 설정 복사
git clone git@github.com:mainbong/inhwa_warehouse.git
cd inhwa_warehouse
cp -r nvim ~/.config/

# 3. Neovim 실행 (플러그인 자동 설치)
nvim
```

**📖 상세 가이드:** [nvim/README.md](./nvim/README.md)

---

## ✨ 주요 기능

- **Modern Plugin Manager**: lazy.nvim
- **Smart Completion**: CoC.nvim (Node.js 있을 때) / Native LSP (없을 때)
- **11개 언어 지원**: Go, Rust, Python, TypeScript, YAML, C/C++, Bash, JSON, Docker, CMake, Lua
- **클라우드 친화적**: Terraform, Kubernetes, Docker, Ansible
- **Fast Navigation**: fzf.vim, nvim-tree, flash.nvim
- **Git 통합**: fugitive + gitsigns
- **Treesitter**: 향상된 구문 강조

## 📂 저장소 구성

```
inhwa_warehouse/
├── nvim/              # Neovim 설정 (최신)
│   ├── README.md     # 상세 사용 가이드 ⭐
│   ├── init.lua
│   └── lua/
│       ├── config/   # 옵션, 키매핑
│       └── plugins/  # 플러그인 설정
├── tmux/              # tmux 설정 (최신)
│   ├── README.md     # 상세 가이드 & 플러그인 설명 ⭐
│   └── .tmux.conf    # tmux 3.4+ 최적화
├── .vimrc           # 레거시 Vim 설정
├── .zshrc           # Zsh 설정
├── .tmux.conf       # tmux 설정 (루트용)
└── bin/             # 유틸리티 스크립트
```

## 🔧 언어 지원

| 언어 | LSP | 자동완성 | 포맷팅 |
|------|-----|----------|--------|
| Go | gopls | ✅ | ✅ |
| Rust | rust-analyzer | ✅ | ✅ |
| Python | pyright | ✅ | ✅ |
| TypeScript/JS | tsserver | ✅ | ✅ |
| C/C++ | clangd | ✅ | ✅ |
| YAML | yamlls + K8s schema | ✅ | ✅ |
| Terraform | terraformls | ✅ | ✅ |
| Docker | dockerls | ✅ | ✅ |
| JSON | jsonls | ✅ | ✅ |
| Bash | bashls | ✅ | ✅ |

## ⌨️ 주요 단축키

| 키 | 기능 |
|----|------|
| `Ctrl+p` | 파일 검색 (fzf) |
| `Ctrl+n` | 파일 트리 토글 |
| `gd` | 정의로 이동 |
| `gr` | 참조 찾기 |
| `K` | 문서 보기 |
| `Tab` / `Shift+Tab` | 버퍼 이동 |
| `<leader>gs` | Git 상태 |

**전체 단축키:** [nvim/README.md](./nvim/README.md)

## 🌐 클라우드 환경 지원

이 설정은 클라우드 인프라 개발에 최적화되어 있습니다:

- ✅ SSH 원격 서버에서 즉시 사용 가능
- ✅ Node.js 없이도 완전한 LSP 기능 (자동 전환)
- ✅ 낮은 리소스 사용 (15MB 메모리)
- ✅ tmux와 완벽한 조합

## 📚 추가 설정

### tmux 설정 (최신 - 권장)

```bash
# 1. tmux 설치
brew install tmux  # macOS
# 또는
sudo apt install tmux  # Ubuntu

# 2. 설정 복사
cp tmux/.tmux.conf ~/

# 3. TPM 설치
git clone https://github.com/tmux-plugins/tpm ~/.tmux/plugins/tpm

# 4. tmux 실행 후 플러그인 설치
tmux
# tmux 안에서: Ctrl+a 그리고 Shift+i
```

**📖 상세 가이드:** [tmux/README.md](./tmux/README.md)

**주요 기능:**
- ✅ 세션 자동 저장/복원 (재부팅해도 유지)
- ✅ 시스템 클립보드 통합
- ✅ 파일/URL 빠른 검색 및 열기
- ✅ Tokyo Night 테마
- ✅ Vim 스타일 네비게이션
- ✅ 9개 강력한 플러그인

**빠른 참조:**
| 기능 | 단축키 |
|------|--------|
| 세션 저장 | `Ctrl+a Ctrl+s` |
| 세션 복원 | `Ctrl+a Ctrl+r` |
| 수평 분할 | `Ctrl+a \|` |
| 수직 분할 | `Ctrl+a -` |
| 패널 이동 | `Ctrl+a h/j/k/l` |
| 파일 검색 | `Ctrl+a Ctrl+f` |
| URL 검색 | `Ctrl+a Ctrl+u` |

### Zsh 설정

#### 1. oh-my-zsh 설치 (미설치 시)

oh-my-zsh가 없으면 먼저 설치해야 합니다.

```bash
# zsh 설치 (없는 경우)
brew install zsh          # macOS
# 또는
sudo apt install zsh      # Ubuntu/Debian

# oh-my-zsh 설치
sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"
```

#### 2. agnoster 테마용 Powerline 폰트 설치

이 설정은 `agnoster` 테마를 사용합니다. 폰트가 없으면 프롬프트가 깨져 보입니다.

```bash
# macOS - Homebrew로 설치
brew install font-meslo-lg-nerd-font
# 터미널 앱(iTerm2, Terminal.app 등)에서 MesloLGS NF 폰트로 변경

# 또는 직접 다운로드
git clone https://github.com/powerline/fonts.git --depth=1
cd fonts && ./install.sh && cd .. && rm -rf fonts
```

> **iTerm2 폰트 설정:** Preferences → Profiles → Text → Font → `MesloLGS NF` 또는 `Meslo LG S for Powerline` 선택

#### 3. zsh-syntax-highlighting 설치

```bash
# macOS
brew install zsh-syntax-highlighting

# Ubuntu/Debian
sudo apt install zsh-syntax-highlighting
# 설치 후 .zshrc의 source 경로 수정 필요:
# source /usr/share/zsh-syntax-highlighting/zsh-syntax-highlighting.zsh
```

#### 4. .zshrc 복사

```bash
cp .zshrc ~/

# 적용
source ~/.zshrc
```

> **참고:** `.zshrc` 내 일부 경로(`/Users/sher.lock/...`)는 본인 환경에 맞게 수정이 필요합니다.

## 🔄 레거시 Vim 설정 (비권장)

<details>
<summary>구 Vim 설정 사용 (클릭하여 펼치기)</summary>

**⚠️ 주의: 이 설정은 더 이상 유지보수되지 않습니다. Neovim 사용을 권장합니다.**

```bash
# Vundle 설치
git clone https://github.com/gmarik/vundle.git ~/.vim/bundle/vundle

# .vimrc 복사
cp .vimrc ~/

# Vim 실행 후 플러그인 설치
vim
:BundleInstall
```

자세한 내용은 [구 README 보기](./OLD_README.md)

</details>

## 🤝 기여

개인 설정 저장소이지만, 자유롭게 Fork하여 사용하세요!

## 📝 License

MIT

---

**마지막 업데이트:** 2024년 12월 24일
**주요 변경사항:** Vim + Vundle → Neovim + lazy.nvim 마이그레이션
