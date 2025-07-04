# godotCpp
Gdextention to develop in godot with c++

## Before we use the git submodule we always should:
git rm -r --cached <path-of-the-.git-repo> (in this case godot-cpp)

 Add a submodule
git submodule add <repository-url> <path>

## what the git submodule command does
Git submodules allow you to keep a Git repository as a subdirectory of another Git repository. Git submodules are simply a reference to another repository at a particular snapshot in time. Git submodules enable a Git repository to incorporate and track version history of external code.

it creates at the root of the repository a file called .gitmodules with the settings and definitions of the submodule that we are pushing.
**It practically tells git were to find the submodule repository we mostly use the command below to get the files from the repo itself without cloning it in our repo**

* Git was confused about which repository controlled the godot-cpp files
* You couldn't push because Git saw conflicting version control systems
* The godot-cpp folder contained its own .git directory, creating a "repository within repository" problem

## Initialize submodules after cloning
git submodule init
git submodule update

## Or do both in one command
git submodule update --init --recursive

## Update submodule to latest commit
git submodule update --remote

## Update specific submodule
git submodule update --remote <submodule-path>

## if you clone my repo you need to
git clone <your-repo>
git submodule update --init --recursive

this is to get the **Latest version of godot-cpp that is the library we are working with in order to develop our nodes in godot**

## To update godot-cpp to latest 4.4 branch:
git submodule update --remote gdextension/godot-cpp

## Commit the submodule update:
git add gdextension/godot-cpp
git commit -m "Update godot-cpp submodule"

