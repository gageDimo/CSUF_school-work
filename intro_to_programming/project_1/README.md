# Project 1 - Pull Requests in Github
<b>Due October 11, 2019, 11:59pm</b>

In Lab 4, you wrote a Rock, Paper, Scissors program that plays a single round of the game. Your project will be to rewrite it for coding style and efficiency, with direct feedback from your instructor via the Pull Request feature in Github.

## Background
In industry, you will almost always collaborate on a large project with lots of code across many files/directories. In order to maintain a high quality code base, new code needs to be properly reviewed.

For teams using git/Github, this is accomplished by working from a <i>branch</i>. The main branch is often called `master`, where everyone's approved code lives, and all proposed changes start in separate <i>branches</i> that are basically snapshots of `master` when the branch started with the proposed changes being developed on top of. A branch would typically be a small change that implements part of a feature or fixes a bug. Once the developer is happy with their changes in their branch, they would send it out for review.

Sending code for review in Github is called a <b>Pull Request</b>. The developer assigns reviewer(s), who leave leave comments about the code from an outsider's perspective for how it can be improved, which are sent back to the developer. The developer addresses the comments in a follow-up change, notifies the reviewer, who if satisfied, can approve the change with a message "LGTM" ("Looks Good To Me" - the most popular comment in Github). Once approved, either the branch can merged into `master` for everyone else to sync to.

## Objectives
* Write clean, concise, readable, maintainable, and efficient code
* Iterate on a solution to a problem and explore various equivalent ways it can be achieved
* Gain familiarity with the code review process in Github, working in branches, sending out pull requests, addressing comments, and merging branches into `master`
* Learn about additional git commands, including
  * `git branch`
  * `git checkout`
  * `git pull`

## Instructions
### Create a branch
After running `git clone` to download the project starter code, `cd` into the project directory as usual in the terminal.

View what branch is currently active using `git branch`. You should see `* master` as the only output. This means `master` is set as the branch that your `git commit/git push`es will go unless otherwise specified (by you, the developer). Typically, `master` refers to the central truth of what the code that ultimately gets shipped to customers is.
```
project1$ git branch
* master
project1$
```
<b>However, `master` requires approval to push to!</b> You will have to work out of a branch, which you will have to create. One easy way to create it is using `git branch <name of the new branch>`. You can choose any name you want, but it should reflect the changes you propose to make. For example:
```
project1$ git branch implement_rock_paper_scissors
project1$
```

To verify your branch was indeed  created, run `git branch` again:
```
project1$ git branch
  implement_rock_paper_scissors
* master
project1$
```

Notice `implement_rock_paper_scissors` now exists as a branch locally, but the `*` is still next to `master`. This means `master` is the active branch. we need to <switch>  branches to `implement_rock_paper_scissors` using `git checkout <name of the branch you want to checkout>`:
```
project1$ git checkout implement_rock_paper_scissors
project1$
```

To verify you're now on the new branch run `git branch` again to see:
```
project1$ git branch
* implement_rock_paper_scissors
  master
project1$
```
### Make changes on the new branch
Now that you're on your new branch, make some code changes to `rock_paper_scissors.cpp`. You may open your existing lab 04 code and paste it directly, or start over if you prefer. The code you commit in this branch will be sent for code review (by your instructor).

Ensure your code is working to your satisfaction, and commit/push it to your new branch.
```
project1$ git status
On branch implement_rock_paper_scissors
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   rock_paper_scissors.cpp

no changes added to commit (use "git add" and/or "git commit -a")
project1$
project1$ git add rock_paper_scissors.cpp
project1$
project1$ git commit -m "Implementing rock, paper, scissors to support playing a single game"
project1$
[implement rock_paper_scissors 47de88b] Implementing rock, paper, scissors to support playing a single game
 1 file changed, 1 insertion(+), 1 deletion(-)
project1$
project1$ git push
```

Notice `git push` now complains!
```
fatal: The current branch implement_rock_paper_scissors has no upstream branch.
To push the current branch and set the remote as upstream, use

    git push --set-upstream origin implement_rock_paper_scissors
```

Don't worry about what all that means, but just run the command it suggests it to get your code committed, and ensure your output looks something like:
```
project1$ git push --set-upstream origin implement_rock_paper_scissors
Enumerating objects: 7, done.
Counting objects: 100% (7/7), done.
Compressing objects: 100% (6/6), done.
Writing objects: 100% (6/6), 662 bytes | 331.00 KiB/s, done.
Total 6 (delta 1), reused 0 (delta 0)
remote: Resolving deltas: 100% (1/1), done.
remote:
remote: Create a pull request for 'implement_rock_paper_scissors' on GitHub by visiting:
remote:      https://github.com/<your repo name>/pull/new/implement_rock_paper_scissors
remote:
To https://github.com/<your repo>.git
 * [new branch]      implement_rock_paper_scissors -> implement_rock_paper_scissors
Branch 'implement_rock_paper_scissors' set up to track remote branch 'implement_rock_paper_scissors' from 'origin'.
```
### Create a Pull Request
On your project page in Github, opposite to the left of the big green button that you use to clone your assignment, you should now see two buttons

`Branch: master` and `New pull request`

Click `New pull request`, and in the two dropdown buttons to compare branches, select `base: master` and `compare: implement_rock_paper_scissors`.

Fill out the <b>Open a pull request</b> form that you are now at. Ensure the following are filled out:
* <b>Subject line:</b> (pre-populated when you ran `git commit -m` earlier, but you can change it to anything you'd like that's informative of what you changed)
* <b>Leave a comment:</b> Ask nicely for your reviewer to look at your Pull Request! Typically developers use "PTAL" which stands for <b>p</b>lease <b>t</b>ake <b>a</b> <b>l</b>ook
* On the right under <b>Reviewers</b> select your instructor (Dr. Shafae, Dr. Sood, or that random jeff-li-gir person who's been making everyone's life difficult the past several weeks... I hear he's a cool guy)
* On the right under <b>Assignees</b> select your instructor as well. <i>This part is mandatory, or nobody will be notified to review your code!</i>

Click the big green button to Create Pull Request! The instructor you specified for the <i>Assignee</i> will receive an email notification to review your code.

### After hearing back with comments
Address all the comments in the code. When you're done, use `git add` `git commit -m` and `git push` just like before in your `implement_rock_paper_scissors` branch. The fact that Github sees a new commit should automatically notify your instructor that you've made updates, which your instructor can then comment on for further revisions that you will then address.

After as many iterations as needed, if your instructor has no more comments on how your code can be further awesomified, they will reply with "lgtm" and check the approval box (on their end). Once this happens, you will be able to <b>merge</b> your branch (big green button) into `master`, and you are done!

### What if I work on different computers?
Say you work on half the assignment during lab, and get your initial pull request sent out. Then 2 days later, you hear back with comments to address, and want to work off your laptop that has Tuffix on it. How do you get your code that you already sent out so you can continue working on it? Run `git clone` again on your new computer!

How do I work off that same branch? use `git branch -a` to view what branches exist, and `git checkout <branch name>` to switch to that branch:
```
project1$ git branch -a
* master
  remotes/origin/HEAD -> origin/master
  remotes/origin/implement_rock_paper_scissors
  remotes/origin/master
project1$
project1$ git checkout implement_rock_paper_scissors
project1$
project1$ git branch
* implement_rock_paper_scissors
  master
project1$
```

Now you can keep working as though nothing happened!

### What if I work on the original computer again, how do I get my changes I made from my laptop?
Since the original computer already has the code downloaded, there's no need to run `git clone` again. Rather, you just need to update it to what's the latest in your `implement_rock_paper_scissors` branch. You can accomplish this using `git pull`, which should result in something that looks like:

```
project1$ git pull
remote: Counting objects: 11, done.
remote: Compressing objects: 100% (5/5), done.
remote: Total 7 (delta 2), reused 0 (delta 0)
Unpacking objects: 100% (7/7), done.
From ssh://my.remote.host.com/~/git/project-01
 * branch            implement_rock_paper_scissors     -> FETCH_HEAD
Updating 9d447d2..f74fb21
Fast forward
 rock_paper_scissors.cpp |   13 +++++++++++++
 1 files changed, 13 insertions(+), 0 deletions(-)
project1$
```

## Grading
In order for code to be committed to the `master` branch, it must be approved by your code reviewer. Only what code is in `master` branch will be graded.

1. (1 point): Your repository utilized at least 1 pull request.
2. (1 point): Your pull request(s) have an assignee (your instructor) set.
3. (1 point): Your pull request(s) have all comments for feedback addressed.
4. (1 point): Your pull request(s) have LGTM and approval from your instructor.
5. (1 point): Your pull request(s) are closed and merged into the `master` branch.
6. (1 point): Your pull request has meaningful commit messages associated with what you changed at each commit (e.g. "Refactoring if statements into fewer lines")
7. (1 point): Your code uses meaningful yet concise variable names with consistent style (all camelCase, or all snake_case).
8. (1 point): Your code has only comments `//` that describe the code they are associated with (e.g. no stray `TODO`s or `HINT`s, no commented code).
9. (1 point): Your code uses consistent whitespace, e.g. denotes which statements belong within which scope (in between `{}`), separates operators from operands (e.g. `a + b` instead of `a+b`), etc.
10. (1 point): Your code passes all the test cases just like in Lab 04.
