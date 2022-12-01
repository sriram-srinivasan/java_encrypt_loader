# An example of how to use the JVMTI interface to decrypt classes


## Overview

We have two kinds of source files.

  1. "precious files", which we would like to keep encrypted on disk, and decrypted and loaded on the fly.  See precious_src/.../Precious.java
  2. ordinary files. See src/.../Main.java

We use a native java agent written in C++ to load and decrypt precious files. In this example, I compile files in `precious_src` to the `precious_classes` directory, then use `tools/base_enc64.py` to "encrypt" these `precious_classes` and to dump the encrypted files into the `enc_precious_classes` directory.

Only the `classes` and `enc_precious_classes` directories are shipped to the customer.

## Build and run

    sh build.sh

The following command works on macos. Change the name of the agent library depending on your platform.

    java -agentpath:./agent_bin/libDecryptAgent.dylib -cp classes:$CLASSPATH net.malhar.Main

## Flow of control

1. Agent dynamic library is loaded.
2. `net.malhar.Main.main` invoked. This class is picked up from `classes/`
3. `main` calls `loadClasses()`, implemented in agent
4. loadClasses loads enc_precious_classes/.../Precious.eclass, decodes it, and loads the bytes to define the `net.malhar.Precious`