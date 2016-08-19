builddir=.

#   the used tools
APXS=apxs
APACHECTL=apachectl

#   additional defines, includes and libraries
LIBS=-ljson-c -lz

# Source
FILES=mod_log_gelf.c mod_log_gelf.h functions.c functions.h functions20.h apache20.h

#   the default target
all: mod_log_gelf


mod_log_gelf: $(FILES)
	$(APXS) $(LIBS) -c $(FILES)  
	

#   install the shared object file into Apache 
install: mod_log_gelf.la
	$(APXS) $(LIBS) -c -i $(FILES)

#   cleanup
clean:
	-rm -f mod_log_gelf.o functions.o functions.lo functions.slo mod_log_gelf.lo mod_log_gelf.slo mod_log_gelf.la 

#   simple test
test: reload
	lynx -mime_header http://localhost

#   install and activate shared object by reloading Apache to
#   force a reload of the shared object file
reload: install restart

#   the general Apache start/restart/stop
#   procedures
start:
	$(APACHECTL) start
restart:
	$(APACHECTL) restart
stop:
	$(APACHECTL) stop

