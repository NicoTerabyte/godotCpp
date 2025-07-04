# godotCpp
Gdextention to develop in godot with c++


# Add a submodule
git submodule add <repository-url> <path>

# Initialize submodules after cloning
git submodule init
git submodule update

# Or do both in one command
git submodule update --init --recursive

# Update submodule to latest commit
git submodule update --remote

# Update specific submodule
git submodule update --remote <submodule-path>


# if you clone my repo you need to
# When someone clones your repo, they need to:
git clone <your-repo>
git submodule update --init --recursive

# To update godot-cpp to latest 4.4 branch:
git submodule update --remote gdextension/godot-cpp

# Commit the submodule update:
git add gdextension/godot-cpp
git commit -m "Update godot-cpp submodule"
