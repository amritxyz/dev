+-----------------------------------------------------------------------
| Running ${PKGSTEM} on OpenBSD
+-----------------------------------------------------------------------

Windowing Problems
==================
If the splash-screen displays but you then only see a grey main screen,
install the wmname package and run 'wmname LG3D'. This is a problem that
has been seen with some Java-based applications used with a non-reparenting
window manager (e.g. cwm).

Native Libraries
================
Functionality depending on native libraries is not likely to work.

Filesystem notifier
===================
Install the intellij-fsnotifier package to use fsNotifier.

Errors After Upgrading
======================
If you receive errors starting after an upgrade, try the following:

1. Remove the ${HOME}/.IdeaICXXXX.Y/config/plugins directory
2. Remove the following directories
  a. ${HOME}/.local/share/JetBrains
  b. ${HOME}/.cache/JetBrains
  c. ${HOME}/.config/JetBrains
3. Relaunch intellij
4. Reinstall the removed plugins

Maintainer
==========
Lucas Raab

Only for arches
===============
aarch64 amd64 i386

Categories
==========
devel java

Build dependencies
==================
    jdk->=17v0,<18v0:devel/jdk/17
    jdk->=17v0,<18v0:devel/jdk/17 

Run dependencies
================
    devel/desktop-file-utils
    java/javaPathHelper
    jdk->=17v0,<18v0:devel/jdk/17 
