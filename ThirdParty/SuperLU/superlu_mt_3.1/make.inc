############################################################################
#
#  Program:         SuperLU
#
#  Module:          make.inc
#
#  Purpose:         Top-level Definitions
#
#  Creation date:   October 2, 1995
#
#  Modified:	    February 4, 1997  Version 1.0
#		    November 15, 1997 Version 1.1
#		    September 1, 1999 Version 2.0
#
############################################################################
#
#  The machine (platform) identifier to append to the library names
#
PLAT = _OPENMP

#
#  The name of the libraries to be created/linked to
#
TMGLIB       	= libtmglib$(PLAT).a
SUPERLULIB   	= libsuperlu_mt$(PLAT).a

# 
# If you don't have ESSL, you can use the following blaslib instead:
#           BLASLIB = -lblas -lxlf -lxlf90
# which may be slower than ESSL
#
#BLASDEF	    = -DUSE_VENDOR_BLAS
#BLASLIB		= -L/usr/lib -lf77blas -latlas
BLASLIB = ../lib/libblas$(PLAT).a
MATHLIB	  = -lm 
MPLIB	  = -qsmp=omp

#  The archiver and the flag(s) to use when building archive (library)
#  If your system has no ranlib, set RANLIB = echo.
#
ARCH         = ar
ARCHFLAGS    = cr
RANLIB       = ranlib

############################################################################
# Definitions used by CPP:
PREDEFS      	= -D__OPENMP
#
CC           = gcc
CFLAGS       = $(PREDEFS) -g -O3 -fPIC
# Uncomment the following to use 64-bit integer
# CFLAGS	    += -D_LONGINT

# There are a few files that should NOT be optimized, which appear in the
# end of SRC/Makefile, taking the flag $(NOOPTS)
# NOOPTS should be defined to explicitly turn off any optimization.
NOOPTS	 = -O0 -fPIC

############################################################################

FORTRAN		 = gfortran
FFLAGS       = -O3

############################################################################

LOADER       	= gcc
LOADOPTS     	= -O #-pthread

############################################################################
#
#  C preprocessor defs for compilation for the Fortran interface
#  (-DNoChange, -DAdd_, -DAdd__, or -DUpCase)
#
CDEFS        	= -DAdd_


