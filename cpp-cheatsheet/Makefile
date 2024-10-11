BASENAME = cpp-cheatsheet

pdf:
	pdflatex -shell-escape $(BASENAME).tex

clean:
	rm -f $(BASENAME).aux $(BASENAME).log $(BASENAME).pdf
	rm -rf _minted-cpp-cheatsheet

.PHONY: pdf clean
