+-----------------------------------------------------------------------
| Running ${PKGSTEM} on OpenBSD
+-----------------------------------------------------------------------

Windowing Problems
==================
If the splash-screen displays but you then only see a grey main screen,
install the wmname package and run 'wmname LG3D'. This is a problem that
has been seen with some Java-based applications used with a non-reparenting
window manager (e.g. cwm).

Filesystem notifier
===================
Install the intellij-fsnotifier package to use fsNotifier.

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
