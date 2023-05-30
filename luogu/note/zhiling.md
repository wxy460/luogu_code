pandoc --toc  --number-sections input.md -o output.docx //可以生成目录
# 前言 {-} //可以在目录编号的额时候不计入
pandoc --filter pandoc-crossref input.md -o output.docx //交互标记
![nature上偷来的图片](https://5b0988e595225.cdn.sohucs.com/images/20190415/14ccde40002e491cb775d81cad9f2342.jpeg){#fig:nature上偷来的图片}
巴拉巴拉巴拉巴拉，见[@fig:nature上偷来的图片]
上面的引用是图片，对应的是fig
表格对应的是tbl
公式对应的是eq
章节对应的是sec
pandoc -F pandoc-crossref --metadata-file metadata.yaml --toc  --number-sections input.md -o output.docx