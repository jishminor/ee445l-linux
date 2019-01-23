#
# Makefile
# Sean Kirmani, 2017-09-17 16:49
#

DIRS=${wildcard ./lab*}

vware_baseurl=http://edx-org-utaustinx.s3.amazonaws.com/UT601x/
vware_zipfile=ValvanoWareTM4C123.zip
vware_destdir=ValvanoWare

init::
	@git config core.hooksPath .githooks
	@git config core.whitespace cr-at-eol
	if [ ! -d ${vware_destdir} ];                     \
	then                                              \
		echo ${vware_destdir}/ >> .gitignore &&       \
		curl -O ${vware_baseurl}${vware_zipfile} &&   \
		unzip ${vware_zipfile} &&                     \
		mv ${vware_zipfile:.zip=} ${vware_destdir} && \
		rm ${vware_zipfile} || exit $$?;              \
	fi;

all: init
	@for i in ${DIRS};                  \
	 do                                 \
	     if [ -f $${i}/Makefile ];      \
	     then                           \
	         make -C $${i} || exit $$?; \
	     fi;                            \
	 done

clean: init
	@rm -f ${wildcard *~} __dummy__
	@rm -f ${wildcard utils/*~} __dummy__
	@for i in ${DIRS};             \
	 do                            \
	     if [ -f $${i}/Makefile ]; \
	     then                      \
	         make -C $${i} clean;  \
	     fi;                       \
	 done

# vim:ft=make
#
