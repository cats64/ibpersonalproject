.PHONY: build clean install packages tools qemu iso

all: build
	@echo "Done."
build:
	@echo Starting build...
	pdflatex journalentries.tex
	pdflatex progress.tex
	pdflatex proposal.tex
	@echo Build done.
clean:
	@echo Cleaning...
	rm -rf *.aux *.log *.out *.toc
	rm -rf texput.log
	@echo Cleaned.
