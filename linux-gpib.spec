Name:         linux-gpib
Version:      4.0.3
Release:      alt1

Summary:      Support package for GPIB (IEEE 488) hardware.
Group:        System/Kernel and hardware
URL:          http://linux-gpib.sourceforge.net/
License:      GPL

Packager:     Vladislav Zavjalov <slazav@altlinux.org>
Source:       %name-%version.tar

BuildPreReq:  kernel-headers-modules-un-def

%description
The Linux GPIB Package is a support package for GPIB (IEEE 488) hardware.
The package contains kernel driver modules, and a C user-space library
with Guile, Perl, PHP, Python and TCL bindings. The API of the C library
is intended to be compatible with National Instrument's GPIB library.

%prep
%setup -q

%build
%autoreconf
%configure --with-linux-srcdir=/usr/src/linux-4.5.4-un-def
%make install DESTDIR=%buildroot

%files
/etc/hotplug/usb/*
/etc/udev/rules.d/*
/etc/gpib.conf
/lib/modules/4.5.4-un-def-alt1/gpib/*
/usr/bin/*
/usr/include/gpib/*
/usr/lib64/*
/usr/sbin/*
/usr/share/usb/*

%changelog
