# Lab 01: Tuffix, Shell, and Github

The purpose of this lab is to get familiar with the UNIX system,
[Tuffix](https://github.com/kevinwortman/tuffix), and GitHub. As part of the
lab, you will get to compile and run the HelloWorld program.

## Goals

* Use Tuffix, and get familiar with the UNIX system.
* Clone a GitHub repository.
* Compile C++ source code and execute the compiled code.
* Edit C++ source code.
* Commit your edit and push it to the GitHub repository.

## Background

### UNIX system

You might be familiar with operating systems like Windows or macOS. UNIX is another operating system that was developed back in 1969 by AT&T Bell labs. Operating systems manage the computer resources such as the memory, hard-drives, keyboard, mouse, screen, etc. For example, whenever you are copying a photo from your camera SD card connected to your computer to the computer's hard-drive, the operating system is taking care of performing this action in the background.

Many operating systems have been developed as an extension, or very similar to the UNIX operating system. Some of these are Linux or macOS.

#### The UNIX Shell

There are many ways to interact with an operating system: you can see the visual screen of your phone and interact with it by touching it, or you can listen to a Google Home device and interact with it by talking to it. One of the most basic ways to interact with an operating system is by using the UNIX shell, which looks like this:

```bash
your_user_name@mylaptop:~$
```

The UNIX shell is a program that expects the user (you) to input commands (using a keyboard in most cases) and then sends your commands to the operating system to be executed on your behalf. There are multiple types of UNIX shells which determine the format/style of commands it expects. In this class, we will be using the *Bash* UNIX shell.

*Note: you might notice that whenever you type your password in the shell, nothing will show up. This is working as intended (security feature). The terminal does let you type your password whenever it is asked, but it does not show any hidden characters as you type it.*

### Git, GitHub & GitHub Classroom

When writing code for a program, it is extremely helpful to keep track of the changes that you have made to your code. Sometimes you realize that a piece of code you recently wrote is actually broken and you need to revert it to an older version. A software that allows you to keep track of your code changes is called a version control system.

In addition, when working in a project with multiple people, programmers might need to update the same file at the same time. A **distributed** version control system allows each member of a team to download a copy of the existing code so that they can work on it locally, and later integrate it with the code from other members of the team. This allows the team to implement a software faster.

Git is a free and open source distributed version control system and is widely used in academia as well as the industry. GitHub is a web-based service that provides an online server to host code online that can be updated using Git. You can think of GitHub the same way you think of Dropbox, but made specifically to integrate with the Git system.

GitHub Classroom is a service that GitHub offers specifically designed for implementing Git in a classroom environment, where students download some code, implement their assignments, and then submit the code through Git, allowing the instructor to see all the submissions. We will be using GitHub classroom in all of the coding assignments of this class (labs and projects).

Git is a extremely powerful tool that allows teams to work on multiple versions of code, and because of this, Git can also get very complicated. For the purposes of this course, we will be learning three basic Git operations that will allow you to submit your assignments:

1. `git clone`, which allows you to download a copy of the code stored in GitHub onto your local computer so that you can edit it locally.
1. `git commit`, which is used to store (or save) a current version of your code (think of it as clicking the save button on a document you are editing).
1. `git push`, which uploads all of the versions you have stored each time you execute `git commit`. You can *commit* your code multiple times, creating multiple versions of your code. For these assignments, we will always only grade the most recent *commit* of your code (which is the most recent version).

We will show you how to use the commands listed above in the lab instructions.

## Pre-requisites

For this assignment, you must have a GitHub account linked to your university email.

If you have never had a GitHub account, you can create one by visiting the [GitHub](https://github.com/) website and filling up the form to sign up for GitHub. Make sure to use your university email when creating the account. Make sure you verify your email (you will get a verification email after creating your account).

If you already have a GitHub account, but it was created using a different email, you need to link your GitHub account to your university email. Log into your account on the GitHub website and then visit the [Email settings](https://github.com/settings/emails) page to add your university email. Once you add your university email, you will receive an email which will allow you to verify that the email belongs to you.

## Lab instructions

### Cloning the Git Repository

One you are logged into your GitHub account, open the assignment URL that your instructor has shared with you. It looks like this: https://classroom.github.com/a/some_random_code

After opening that link, GitHub will generate the your own repository that will contain the starter code of the lab. This is the same repository where you will be pushing (submitting) your code for grading. Once the repository is generated, a similar message will show:

> Your assignment has been created here: https://github.com/CSUF-CPSC-120-LW/lab-01-your_user_name

Open the link to see the web-view of your GitHub repository. In there you will see two files:

1. `README.md`: an exact copy of the file you are reading right now.
1. `helloworld.cpp`: the starter code for your lab assignment.

Now we need to clone your repository into your local computer so that you can start working with that code. To keep your files organized, we will first create a folder for this class, and in that folder we will clone your repository.

#### Creating a folder

By default, opening a terminal (or ssh'ing into the university's computers) will take you straight to your home directory, which is usually referred as `~`. If you are using Tuffix, the location of your home directory is `/home/your_user_name` (you can check by running the `pwd` command).

Let's go ahead and create a folder in your home directory called `cpsc120` by running the following command:

```
~$ mkdir cpsc120
```

After you press enter, the folder cpsc120 will be created, which you can verify by listing all the files and folder under your home directory:

```
~$ ls
cpsc120 Desktop Documents ...
```

#### Accessing the folder (changing a directory)

Now, let's enter the folder so that you can clone your repository inside. We are going to use the `cd` command, which stands for *change directory*:

```
~$ cd cpsc120
~/cpsc120$
```

You can notice now that, right before the `$` sign, the directory is now `~/cpsc120` instead of just `~`.

#### Cloning the git repository

Now we are ready to clone your repository. Go back to the web-view of your GitHub repository and click on the **Clone or download** green button on the top right, and then click on the copy button right next to the repository address. Then, go back to the terminal and run the following command:

```
~/cpsc120$ git clone <paste repository URL>
```

The command will ask you to input your GitHub username and password. Once you enter that information, the repository is then downloaded (cloned) into your computer. The whole process will look similar to this:

```bash
~/cspc120$ git clone https://github.com/CSUF-CPSC-120-LW/lab-01-your_user_name.git
Username for 'https://github.com': your_user_name
Password for 'https://github.con':
Cloning into 'lab-01-your_user_name'...
remote: Counting objects: 9, done.
remote: Compressing objects: 100% (6/6), done.
remote: Total 9 (delta 1), reused 9 (delta 1), pack-reused 0
Unpacking objects: 100% (9/9), done.
```

Now you can notice that there is a new folder called `lab-01-your_user_name`:

```
~/cpsc120$ ls
lab-01-your_user_name
```

Let's access that folder and look at the contents:

```
~/cpsc120$ cd lab-01-your_user_name
~/cpsc120/lab-01-your_user_name$ ls
README.md helloworld.cpp
```

As you can see, a copy of the two files that you saw on the web-view of your GitHub repository have been downloaded (cloned) into your computer. You have successfully cloned your lab assignment's git repository.

### Compiling and executing code

The file `helloworld.cpp` contains source code for the HelloWorld program, written in C++. HelloWorld is a program that prints "Hello World!" in the terminal whenever it is executed. As you will learn later in the class, source code must first be compiled so that it can be executed in the computer. Let's go ahead and compile the source code.

#### Compiling source code

Tuffix comes with the `g++` compiler installed. Let's take a quick look at the contents of that file using the `cat` command, which prints the contents of the file in the terminal. Run the command `cat helloworld.cpp`:

```
~/cpsc120/lab-01-your_user_name$ cat helloworld.cpp
// HelloWorld program
#include <iostream>

int main()
{
  std::cout << "Hello World!\n";
}
```

To compile the `helloworld.cpp` source code, run the following command:

```
~/cpsc120/lab-01-your_user_name$ g++ helloworld.cpp
```

Now you will see that a new file `a.out` has been created:
```
~/cpsc120/lab-01-your_user_name$ ls
a.out helloworld.cpp README.md
```

This file is the compiled version of the source code, which we call a binary file (you will learn more about this later). This file is also an executable file, which means that we can run/execute it. Let's go ahead and execute the code.

#### Executing code

To execute or run the code, you need to append the prefix `./` to the name of the binary file. Type `./a.out` in the terminal and press enter. That will run the code and print any outputs that the code generates. It should print the following:

```
~/cpsc120/lab-01-your_user_name$ ./a.out
Hello World!
```

Now you have successfully compiled and executed C++ code!

### Editing code

As you saw when running `cat helloworld.cpp`, source code is just a plain text file, which means that you could use a text editor to edit the contents of the file. However, because we have to make sure the contents are plain text (no bold, underline, italics, etc), it is safer to use a code editor rather than a text editor (such as Microsoft Word or WordPad). There are many types of code editors, some are very basic and straight forward, while other comes with advance features such as code coloring, code suggestions, auto-formatters, etc. For this class, we will be using [Atom](https://atom.io/), an open-source text editor. Atom is already installed in Tuffix, however you cannot run Atom when accessing a computer through SSH. If you are planning on doing so, please let me know so that I can help you with alternate options for code editing.

You can open Atom by simply running `atom` in the terminal. However, you will need to find the file you want to edit when opening the program. If you want to open directly the program with the file you want to edit, you can pass the name of the file as the first argument of the `atom` command. In our case, it will be `helloworld.cpp`:

```
~/cpsc120/lab-01-your_user_name$ atom helloworld.cpp
```

Now that Atom is open, go ahead and edit the `helloworld.cpp`. Make the following changes:

1. Change the comment line (the one starting with ```//```) to say your full name
  and which section of CPSC 120 you are attending. For example, if your name is
  Jane Doe and you are in CPSC 120-01, the comment should look something like
  ```
  // Jane Doe (CPSC 120-01)
  ```
  This step is necessary so that we can record your grade for the lab.

1. Replace "world" with your name, so that when you run it, it will print out "Hello Jane!" (instead of *Jane*, it will be your name).
  This step is the one that personalizes the `helloworld` program so that it behaves
  the way that you want it to.

Once you make the edit, save the file and verify that it works correctly by compiling the code again and running it.

### Pushing code to Git (submitting your assignment)

To submit your code, you will need to add the files that you want to submit, commit your changes, and push them into the GitHub repository.

#### Adding the files

From the time you cloned the repository to now, there are two changes to the folder:

1. A new file `a.out` exists
1. The `helloworld.cpp` file was modified.

You can verify this by running `git status`, which should display the following:

```
~/cpsc120/lab-01-your_user_name$ git status
On branch master
Your branch is up to date with 'origin/master'.

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   helloworld.cpp

Untracked files:
  (use "git add <file>..." to include in what will be committed)

	a.out

no changes added to commit (use "git add" and/or "git commit -a")
```

That information is telling two things: there is a modification to the `helloworld.cpp` file and there is a new (untracked) file `a.out` that didn't exist before when you cloned the repository.

When submitting lab assignments or your project in this class, you will never be asked to submit the compiled code (in this case, the file `a.out`). We will take care of compiling it for you and running it for you when grading your assignment. That means that you just need to submit the `helloworld.cpp` file.

In Git, you can only submit *commits*. A commit can be composed of multiple actions such as modifying a file, adding a new file, deleting a file. In this case, we just want to commit the modification you made to `helloworld.cpp`, so we first need to add `helloworld.cpp` to the commit by running the following command:

```
~/cpsc120/lab-01-your_user_name$ git add helloworld.cpp
```

Now when you run `git status`, you will notice that the `modified: helloworld.cpp` line is under *Changes to be committed* rather than *Changes not staged for commit*.

#### Committing your changes

To commit your changes (which in this case is was due to a single file), you run the command `git commit -m "Some quick description here"`. The `-m` indicates that the next parameter will be a description of your commit. The description should always be a sentence explaining what your change is about, and should be readable and useful for other engineers/programmers to understand what your change did. Some examples of commit descriptions could be *"Fixed bug that was causing the camera app to crash."* or *"Implemented the search feature for the project."*

In our case, you can use the description *"Changed the hello world message to show my name."* by running the following command:

```
~/cpsc120/lab-01-your_user_name$ git commit -m "Changed the hello world message to show my name."
```

That command will output a message similar to this one:

```
[master 7374384] Changed the hello world message to show my name.
 1 file changed, 1 insertion(+), 1 deletion(-)
```

Something to notice in there is the line that says `1 file changed, 1 insertion(+), 1 deletion(-)`. It is a summary of how much stuff has changed in this commit. As we know, we modified 1 file. However, it also says that there was 1 insertion and 1 deletion. Those two measures are referring to how many lines were inserted and how many lines were deleted respectively. Git doesn't measure how many lines were modified, that means that if you modify a line, it will treat it as deleting that line and adding a new one with your modification.

#### Pushing your commit to GitHub

The last step is to push (upload) your commit to GitHub. Running the following command will upload your commit, which includes the files you added or edited, as well as the commit message:

```
~/cpsc120/lab-01-your_user_name$ git push
```

If everything went well, you should see a message similar to this one:

```
Counting objects: 3, done.
Delta compression using up to 8 threads.
Compressing objects: 100% (3/3), done.
Writing objects: 100% (3/3), 340 bytes | 340.00 KiB/s, done.
Total 3 (delta 1), reused 0 (delta 0)
remote: Resolving deltas: 100% (1/1), completed with 1 local object.
To https://github.com/CSUF-CPSC-120-LW/lab-01-your_user_name
```

If you open the URL of your Git repository, you will see a blue row right above the list of files that shows your last commit. It will say something like this:

```
your_user_name Changed the hello world message to show my name. Latest commit 7374384  1 minute ago
```

You can try clicking on the commit number (in the example above, that would be `7374384`) to open a web-view of the commit you made.

This is the end of the lab :) Please call your instructor or lab assistant to make sure that your commit was successfully submitted.

## Grading (10 points)
1. (3 points): Your GitHub account exists, registered with your @fullerton.edu email address
2. (2 points): Your lab1 repository exists, named appropriately, e.g. https://github.com/CSFU-CPSC-120-FA19/lab-01-your_user_name
3. (2 point): Your updated helloworld.cpp has your name in the comment line
4. (1 point): Your updated helloworld.cpp has your section number in the comment line
5. (1 point): Your updated helloworld.cpp prints the hello message with your name instead of "world"
6. (1 point): Your commit message describes the main point of what you changed, e.g. "Changed the hellow world message to show my name"


## Additional readings

I suggest that you read the following websites to understand and learn more about Git and g++, since you will be heavily using them throughout the labs and projects in this class.

- https://guides.github.com/introduction/git-handbook/ (10-minute read)
- https://www.cprogramming.com/g++.html (5-minute read)
- https://maker.pro/linux/tutorial/basic-linux-commands-for-beginners (basic commands, 10-minute read)
