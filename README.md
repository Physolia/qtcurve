# Installation
## Build and install

    mkdir build
    cd build
    cmake .. -DCMAKE_INSTALL_PREFIX=/usr
    make
    make install

## CMake configure arguments
1. `ENABLE_QT4`:

    Building QtCurve Qt4 theme.

    (Default: `On`)

2. `ENABLE_QT5`:

    Building QtCurve Qt5 theme.

    (Default: `On`)

3. `ENABLE_GTK2`:

    Building QtCurve Gtk2 theme. Require `QTC_ENABLE_X11`.

    (Default: `On`)

4. `QTC_ENABLE_X11`:

    Enable X11 support. Require `xcb`, `xlib-xcb`. Will cause all shared
    libraries to link to `libxcb`, and `libqtcurve-utils.so` will also
    link to `libX11-xcb` and `libX11`.

    (Default: `On`)

5. `QTC_INSTALL_PO`:

    Install `*.po` translation files.

    (Default: `On`)

6. `QTC_QT4_ENABLE_KDE`:

    Compile QtCurve qt4 style with KDE support and dependencies.

    (Default: `On`)

7. `QTC_QT4_ENABLE_KWIN`:

    Compile QtCurve qt4 kwin style. This will only have effect when KDE support
    is turned on. Also require `QTC_ENABLE_X11`.

    (Default: `On` if kwin header is found and KDE support is on,
    `Off` otherwise)

8. `QTC_KDE4_PREFIX`:

    The install prefix of KDE4.

    (Default: the value returned by `kde4-config` or `${CMAKE_INSTALL_PREFIX}`
    if `kde4-config` is not found.)

9. `QTC_KDE4_ICONS_PREFIX`:

    The path of KDE4 icons.

    (Default: `${QTC_KDE4_PREFIX}/share/icons`)

## Deprecated and temporary options.
These compile options were used to turn on/off some experimental features or
work around for certain hardware/software/drivers. It is not guaranteed that
any of the non-default value of these options can work and some of these
options may crash certain applications. They may also be removed at any time
(especially the ones to work around old hardware or driver bugs) and are not
recommanded to turn on in distribution packages.

1. `QTC_QT4_OLD_NVIDIA_ARROW_FIX`:

    Due to QtCurve mixing AA-drawing, with non-AA drawing (specifically for
    arrows) - sometimes the arrows would not draw correctly under NVidia. To
    work-around this, QtCurve filled the arrows using AA-ed drawing, and used
    non-AA drawing for the edges. As of 0.69.0 this code is no longer enabled
    by default - use this config option to re-enable the code.

    (Default: `Off`)

2. `QTC_QT4_STYLE_SUPPORT`:

    Support QtCurve style files. These are stored as
    `<kde prefix>/share/apps/kstyle/themes/qtc_<stylename>.themerc`
    Note that this is not supported in Qt5.

    (Default: `Off`)

3. `QTC_GTK2_MODIFY_MOZILLA`:

    1. Modify `userChrome.css`

        1. setting KDE button order
        2. shrink size of toolbars

    2. Edit `user.js`

        1. disable instant apply

    **Note**: This sometimes causes issues with newer versions of these
    applications. Should such issues occur, you should recompile
    QtCurve without this option - and you will have to remove BY HAND
    the changes that QtCurve has made. This will entail removing lines
    from `userChrom.css` that indicate 'Added by QtCurve'. `userChrome.css`
    is usually in a folder such as:
    `~/.mozilla/firefox/xxxxxxx.default/chrome/userChrome.css` or
    `~/.thunderbird/xxxxxxx.default/chrome/userChrome.css`
    Where xxxxxxx is a series of random characters.

    (Default: `Off`)

## Tips for compiling with `clang`/`clang++`
As of clang version 3.3, `clang++` does not seem to be compatible with the c++
standard library headers shipped with gcc in c++0x mode. If you have problems
compiling the Qt4/Qt5 themes with `clang++`, one possible solution is to use
`libc++` instead of `libstdc++`. The following command should configure
CMake to use `clang`/`clang++` and `libc++` correctly,

    CC=clang CXX=clang++ CPP=clang++ CXXFLAGS="${CXXFLAGS} -stdlib=libc++" LDFLAGS="${LDFLAGS} -lc++abi" cmake .. <other compile options...>

# Additional Features
## XBar/MacMenu
The XBar support was copied directly from Bespin. The relevant files are named
`macmenu.*`. These were taken from revision 652.

**Deprecated** in favor of appmenu since KWin has builtin support for that
after `4.10` and `appmenu-qt` does not depend on a certain theme.

## Themes
As of v0.55, you can create QtCurve based themes. These will appear with KDE's
style control panel's combobox of styles. To create a new theme, select
'QtCurve' from within KDE's style panel, then configure QtCurve as required.
After this, in QtCurve's config dialog, select 'Export theme' from the options
menu button. You will then be prompted to give your new 'theme' a name, and a
comment. QtCurve will then create a file named `qtc_<name>.themerc`
(e.g. `qtc_klearlooks.themerc`) - this will have the following format:

    [Misc]
    Name=Klearlooks
    Comment=Clearlooks inspired style
    [KDE]
    WidgetStyle=qtc_klearlooks
    [Settings]
    animatedProgress=false
    appearance=gradient
    ....rest of qtcurve settings...

To use this theme, either copy `qtc_<name>.themerc` to
`$KDEHOME/share/apps/kstyle/themes/`
(usually `~/.kde/share/apps/kstyle/themes/`)
or copy to `<kde install prefix>/share/apps/kstyle/themes/`
(usually `/usr/share/apps/kstyle/themes/`)

When KDE's style panel is restarted, your new theme should appear in the list.

**NOTE**: As of QtCurve 1.0.0 style support has been disabled by default (enable
via `QTC_QT4_STYLE_SUPPORT`) and this is not supported by Qt5.

## Testing
As of v1.2.1, QtCurve can be forced to read its settings from an alternate
config file via the `QTCURVE_CONFIG_FILE` environment variable. This is only
really useful for testing alternate config settings without changing the users
current settings.

Usage:

    QTCURVE_CONFIG_FILE=~/testfile kcalc

# License
QtCurve `1.8.17` and earlier was licensed under GPLv2+. It was relicensed under
LGPLv2.1+ on Nov. 14th 2013 in order to avoid confusion for moving into
KDE-infrastructure. This relicensing have got permissions from all contributors
of QtCurve (`git log --format='%aN <%aE>' | sort -u`):

    Andrey Bondrov <andrey.bondrov@rosalab.ru>
    Boris Pek <tehnick-8@yandex.ru>
    Craig Drummond <craig.p.drummond@gmail.com>
    Sven-Hendrik Haase <sh@lutzhaase.com>
    Yichao Yu <yyc1992@gmail.com>
