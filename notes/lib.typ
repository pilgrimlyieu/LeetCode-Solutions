/// LeetCode 笔记共享样式库

/// 字体

#let zh-shusong = ("FZShuSong-Z01", "FZShuSong-Z01S")
#let zh-xiaobiaosong = ("FZXiaoBiaoSong-B05", "FZXiaoBiaoSong-B05S")
#let zh-kai = ("FZKai-Z03", "FZKai-Z03S")
#let zh-hei = ("FZHei-B01", "FZHei-B01S")
#let zh-fangsong = ("FZFangSong-Z02", "FZFangSong-Z02S")

#let font-text = (
  (name: "Times New Roman", covers: "latin-in-cjk"),
  ..zh-shusong,
)
#let font-heading = (
  (name: "Times New Roman", covers: "latin-in-cjk"),
  ..zh-xiaobiaosong,
)
#let font-strong = (
  (name: "Times New Roman", covers: "latin-in-cjk"),
  ..zh-hei,
)
#let font-emph = (
  (name: "Times New Roman", covers: "latin-in-cjk"),
  ..zh-kai,
)
#let font-quote = (
  (name: "Times New Roman", covers: "latin-in-cjk"),
  ..zh-fangsong,
)
#let font-code = (
  (name: "JetBrainsMono NF", covers: "latin-in-cjk"),
  ..zh-fangsong,
)

/// 颜色

#let accent = rgb("#ffa116") // LeetCode 橙
#let ink = rgb("#1a1a1a")
#let subtle = luma(115)

// 难度三色沿用 LeetCode 官方色
// Medium 压深一档以保证纸面可读
#let difficulty-scheme = (
  Easy: (label: "简单", color: rgb("#00b8a3")),
  Medium: (label: "中等", color: rgb("#f5a300")),
  Hard: (label: "困难", color: rgb("#ff375f")),
)

/// 组件

// 难度徽章
#let difficulty-badge(d) = {
  let fallback = (label: if d == "" { "—" } else { d }, color: luma(140))
  let info = difficulty-scheme.at(d, default: fallback)
  box(
    fill: info.color.lighten(90%),
    radius: 3pt,
    inset: (x: 6.5pt, y: 3.5pt),
    text(font: font-strong, weight: "bold", size: 9pt, fill: info.color.darken(12%), info.label),
  )
}

// 标签胶囊
#let tag-pill(t) = box(
  fill: luma(243),
  radius: 8pt,
  inset: (x: 7pt, y: 3pt),
  text(font: font-emph, size: 8pt, fill: luma(90), t),
)

// 时空复杂度行：#complexity(time: $O(n)$, space: $O(1)$)
#let complexity(time: none, space: none) = {
  let chip(name, val, c) = box(
    fill: c.lighten(93%),
    radius: 3pt,
    inset: (x: 8pt, y: 4.5pt),
  )[#text(font: font-strong, weight: "bold", size: 8.5pt, fill: c.darken(18%), name)#h(7pt)#val]
  if time != none {
    chip("时间", time, rgb("#2563eb"))
    h(8pt)
  }
  if space != none {
    chip("空间", space, rgb("#7c3aed"))
  }
}

// 醒目框：#pitfall[...]、#tip[...]、#variant[...]、#takeaway[...]，
// 或自定义 #callout(title: .., color: ..)[...]
#let callout(title: "注意", color: accent, body) = block(
  width: 100%,
  fill: color.lighten(94%),
  stroke: (left: 2.5pt + color.lighten(20%)),
  radius: (top-right: 3pt, bottom-right: 3pt),
  inset: (x: 11pt, y: 9pt),
  breakable: false,
)[
  #text(font: font-strong, weight: "bold", size: 1em, fill: color.darken(15%), title)
  #v(1em, weak: true)
  #body
]
#let pitfall = callout.with(title: "坑点", color: rgb("#ff375f"))
#let tip = callout.with(title: "技巧", color: rgb("#00b8a3"))
#let variant = callout.with(title: "变体", color: rgb("#7c3aed"))
#let takeaway = callout.with(title: "总结", color: rgb("#2563eb"))

/// 文档模板

#let note(
  id: "",
  title: "",
  slug: "",
  difficulty: "",
  date: "",
  tags: (),
  body,
) = {
  set document(title: id + ". " + title)
  set page(
    paper: "a4",
    margin: (x: 2.2cm, top: 2.2cm, bottom: 2.4cm),
    footer: context {
      if counter(page).final().first() > 1 {
        align(center, text(size: 8pt, fill: subtle, counter(page).display("1 / 1", both: true)))
      }
    },
  )
  set text(font: font-text, size: 10.5pt, fill: ink, lang: "zh", region: "cn")
  set par(justify: true, leading: 0.85em, spacing: 1.1em)
  set heading(numbering: "1.")
  set list(indent: 0.6em)
  set enum(indent: 0.6em)

  show heading: set text(font: font-heading, weight: "bold")
  show heading.where(level: 1): it => block(above: 1.6em, below: 0.9em)[
    #box(baseline: 12%, rect(width: 3pt, height: 0.85em, fill: accent, radius: 1.5pt))
    #h(0.45em)
    #if it.numbering != none [#counter(heading).display(it.numbering)#h(0.35em)]#it.body
  ]
  show strong: set text(font: font-strong)
  show emph: set text(font: font-emph)
  show quote.where(block: true): set text(font: font-quote)
  show link: set text(fill: rgb("#2563eb"))

  show raw: set text(font: font-code)
  show raw.where(block: true): it => block(
    width: 100%,
    fill: luma(249),
    stroke: 0.5pt + luma(228),
    radius: 4pt,
    inset: 9.5pt,
    text(size: 8.8pt, it),
  )
  show raw.where(block: false): box.with(
    fill: luma(245),
    radius: 2.5pt,
    inset: (x: 3.5pt),
    outset: (y: 2.5pt),
  )

  block(below: 0.4em)[
    #text(font: font-heading, size: 16.5pt, weight: "bold")[#id. #title]
    #h(9pt)
    #difficulty-badge(difficulty)
  ]
  if tags.len() > 0 {
    tags.map(tag-pill).join(h(5pt))
    v(2pt)
  }
  text(size: 8.8pt, fill: subtle)[
    #date
    #if slug != "" [
      #h(1.1em)
      #link("https://leetcode.cn/problems/" + slug + "/")[
        #text(fill: subtle)[leetcode.cn/problems/#slug]
      ]
    ]
  ]
  v(4pt)
  line(length: 100%, stroke: 0.6pt + luma(205))

  body
}
