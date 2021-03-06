Name:         linux-gpib
Version:      4.0.3
Release:      alt1

Summary:      Support package for GPIB (IEEE 488) hardware.
Group:        System/Kernel and hardware
URL:          http://linux-gpib.sourceforge.net/
License:      GPL

Packager:     Vladislav Zavjalov <slazav@altlinux.org>
# I am building this package with gear+rpmbuild locally.
# It works for me with agilent 82357b device and un-def kernel
# (some non-free firmware from http://linux-gpib.sourceforge.net/ also needed).
# To pack it for Altlinux some additional work needed (because of kernel modules).
# If you will do this work, please let me know.

Source:       %name-%version.tar
BuildPreReq:  kernel-headers-modules-un-def
Requires:     fxload


%description
The Linux GPIB Package is a support package for GPIB (IEEE 488) hardware.
The package contains kernel driver modules, and a C user-space library
with Guile, Perl, PHP, Python and TCL bindings. The API of the C library
is intended to be compatible with National Instrument's GPIB library.


%prep
%setup -q

%build
%autoreconf
%configure --with-linux-srcdir=/usr/src/linux-4.8.14-un-def
%make install DESTDIR=%buildroot

%pre
%_sbindir/groupadd -r -f gpib 2> /dev/null ||:

%files
/etc/hotplug/usb/*
/etc/udev/rules.d/*
%config(noreplace) %_sysconfdir/gpib.conf
/lib/modules/4.8.14-un-def-alt1/gpib/*
/usr/bin/*
/usr/include/gpib/*
/usr/lib64/*
/usr/sbin/*
/usr/share/usb/*

%changelog
