.PHONY: build clean install packages tools qemu iso

all: build
	@echo "Done."
build:
	@echo Starting build...
	# This is done twice for the sake of re-generating the ToC
	pdflatex journalentries.tex
	pdflatex journalentries.tex
	pdflatex progress.tex
	pdflatex progress.tex
	pdflatex proposal.tex
	pdflatex proposal.tex
	@echo Build done.
clean:
	@echo Cleaning...
	rm -rf *.aux *.log *.out *.toc
	rm -rf texput.log
	@echo Cleaned.
