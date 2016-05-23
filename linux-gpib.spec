Name:         linux-gpib
Version:      4.0.3
Release:      alt1

Summary:      Support package for GPIB (IEEE 488) hardware.
Group:        System/Kernel and hardware
URL:          http://linux-gpib.sourceforge.net/
License:      GPL

Packager:     Vladislav Zavjalov <slazav@altlinux.org>
Source:       %name-%version.tar

%description
The Linux GPIB Package is a support package for GPIB (IEEE 488) hardware.
The package contains kernel driver modules, and a C user-space library
with Guile, Perl, PHP, Python and TCL bindings. The API of the C library
is intended to be compatible with National Instrument's GPIB library.

%prep
%setup -q

%build
%configure
%make install DESTDIR=%buildroot

%files

%changelog
