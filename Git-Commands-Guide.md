# Git Commands Guide for Embedded-Systems

This guide explains the most common Git commands you need for branch creation, merging, rebasing, history, and pushing changes. It is written for the repository at `C:\Users\amora\Desktop\Embedded C\Embedded-Systems`.

---

## 1. Current Branch and Repository State

- Show current branch:
  ```powershell
  git branch --show-current
  ```

- Show all branches:
  ```powershell
  git branch
  ```

- Show branch list with remote branches:
  ```powershell
  git branch -a
  ```

- Show current repository status:
  ```powershell
  git status
  ```

- Show remote configuration:
  ```powershell
  git remote -v
  ```

---

## 2. Create a New Branch

### Create a branch from the current branch and switch to it

If you are on the branch you want to start from (for example `main`), run:
```powershell
cd "C:\Users\amora\Desktop\Embedded C\Embedded-Systems"
git checkout -b Develop
```

This does two things:
- creates a new branch named `Develop`
- switches your working tree to `Develop`

### Create a new branch without switching

```powershell
git branch Develop
```

Then switch later with:
```powershell
git checkout Develop
```

### Create a branch from another branch explicitly

```powershell
git checkout -b Develop main
```

This creates `Develop` starting from the `main` branch, even if you are currently on another branch.

---

## 3. Push a Branch to GitHub

### Push the current branch to the remote named `origin`

```powershell
git push origin Develop
```

### Push and set upstream so future pushes use the same remote branch

```powershell
git push -u origin Develop
```

After this, later only `git push` works from `Develop`.

---

## 4. Merge Branches

### Merge a branch into the current branch

First switch to the branch that should receive the changes:
```powershell
git checkout main
```

Then merge another branch into it:
```powershell
git merge Develop
```

This applies the commits from `Develop` into `main`.

### Fast-forward merge

If `main` has not moved since you branched, Git may fast-forward:
```powershell
git checkout main
git merge Develop
```

No merge commit is created if Git can simply move `main` forward.

### Merge with a commit even when fast-forward is possible

```powershell
git merge --no-ff Develop
```

This creates a merge commit and preserves a visible branch point.

---

## 5. Rebase Branches

### What rebase does

Rebase moves your branch commits so they appear on top of another branch. It rewrites commit history for your branch.

### Rebase the current branch onto another branch

From `Develop`:
```powershell
git checkout Develop
git rebase main
```

This replays `Develop` commits on top of the latest `main`.

### Rebase another branch without checking it out

```powershell
git checkout Develop
git rebase main
```

### Rebase vs merge

- `merge` creates a merge commit and preserves the branch history as-is.
- `rebase` rewrites commits so the branch looks like it started from a newer commit.

### When to use rebase

- Use rebase to keep your feature branch history linear.
- Do not rebase shared public branches that other people are using.

---

## 6. Working with Commits

### Stage files for commit

```powershell
git add <file>
```

Example:
```powershell
git add README.md
```

### Commit staged changes

```powershell
git commit -m "Add Develop branch guide"
```

### Amend the most recent commit

```powershell
git commit --amend
```

### View commit history

```powershell
git log --oneline --graph --decorate --all
```

---

## 7. Undo and Reset

### Discard local changes to a file

```powershell
git checkout -- <file>
```

### Unstage a file after `git add`

```powershell
git restore --staged <file>
```

### Reset branch to a previous commit

```powershell
git reset --hard <commit-hash>
```

Use `--hard` very carefully; it deletes local changes.

---

## 8. SSH Setup and Using SSH Remote

### Switch remote from HTTPS to SSH

```powershell
git remote set-url origin git@github.com:omar-abedmouleh/Embedded-Systems.git
```

### Test SSH connection to GitHub

```powershell
ssh -T git@github.com
```

### Why SSH is useful

- avoids repeated username/password or PAT prompts for Git
- uses your SSH public key from `C:\Users\amora\.ssh\id_ed25519.pub`
- works with GitHub account `omar-abedmouleh`

---

## 9. Common Git Workflows

### Create a feature branch and merge it back

```powershell
# start from main
git checkout main
git pull origin main
# create feature branch
git checkout -b Develop
# work, stage, commit
git add .
git commit -m "Work on Develop"
# push branch to GitHub
git push -u origin Develop
# merge back into main
git checkout main
git merge Develop
# push main
git push origin main
```

### Rebase a feature branch before merging

```powershell
git checkout main
git pull origin main
git checkout Develop
git rebase main
git checkout main
git merge Develop
git push origin main
```

This keeps history linear and places `Develop` changes after the latest `main` commits.

---

## 10. Helpful Notes

- If Git says you are on branch `Develop`, you are working on that branch.
- `git checkout -b Develop` is the most common way to create a branch and switch to it.
- Use `git push -u origin Develop` only once per branch; after that `git push` is enough.
- Use rebase for local branch cleanup; use merge for shared branch integration.

---

## 11. Example: Create `Develop` Branch from `main`

```powershell
cd "C:\Users\amora\Desktop\Embedded C\Embedded-Systems"
git checkout main
git pull origin main
git checkout -b Develop
git push -u origin Develop
```

This creates `Develop` from the latest `main`, switches to it, and pushes it to GitHub.
