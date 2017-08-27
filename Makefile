COURSE  = cosc2325
TERM    = fall2017
LOCALDIR = _build/html/
REMOTEDIR   = www/courses/$(COURSE)

.PHONY: all
all:    build

.PHONY: reqs
# target: reqs - create virtual env and add requirements
reqs:  _venv
	source ./_venv/bin/activate; \
	pip install -r requirements.txt;


_venv:
	virtualenv _venv

.PHONY: build
# target: build - run sphinx on rst files to gen html output
build:
	sphinx-build -b html -d _build/doctrees . _build/html

.PHONY: test
# test - check spelling of all website pages
test:
	sphinx-build -b spelling -d _build/doctrees . _build/spelling
	sphinx-build -b linkcheck -d _build/doctrees . _build/linkcheck


.PHONY: sync
# target: sync - upload local image to website
sync:   all
	rsync -arvuz $(LOCALDIR) rblack@www.co-pylit.org:$(REMOTEDIR)
clean:
	rm -rf _build/

.PHONY: help
# target: help - Display all callable targets
help:
	@echo
	@egrep "^\s*#\s*target\s*:\s*" [Mm]akefile \
		| sed -E "s/^\s*#\s*target\s*:\s*//g"
	@echo
