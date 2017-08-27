# Example C++ project Makefile

# primary build files ----------------------------------
TARGET  = example
TESTAPP = test_runner

# primary targets depend on this librry
LIB     =   demolib
LIBS    =   libs

# tools needed at this level
RM      = rm -f

# project directories
SRCDIR  = src
INCDIR  = include
LIBDIR  = src/lib
TSTDIR  = tests
DOCDIR  = docs

# targets ----------------------------------------
all:    $(TARGET) $(TESTAPP)

$(TARGET):  $(SRCOBJS) $(LIB)
		$(CXX) -o $(TARGET) $(SRCOBJS) $(LDFLAGS)

.PHONY: $(LIB)
$(LIB):
		$(MAKE) -C $(LIBDIR)

$(TESTAPP): $(TSTOBJS) $(LIB)
		$(CXX) -o $(TESTAPP) $(TSTOBJS) $(LDFLAGS)

run:    $(TARGET)
		./$(TARGET)

test:   $(TESTAPP)
		./$(TESTAPP)

clean:
		$(RM) $(ALLOBJS) $(TARGET) $(TESTAPP)
		$(MAKE) -C src/lib clean
		$(MAKE) -C tests clean

# create dependency files
dep:    $(DEPS)
		$(MAKE) -C $(TSTDIR) $(DEPS)
		$(MAKE) -C $(LIBDIR) $(DEPS)

# dependency target
$(DEPS):    $(SRCFILES) $(INCFILES)
		$(CXX) -M $(CXXFLAGS) $(SRCFILES) > $(DEPS)


# read the dependency file for this level
include $(DEPS)

# implicit targets
%.o:    %.cpp
		$(CXX) -c $(CXXFLAGS) -o $@ $<


.PHONY: all run test clean dep
