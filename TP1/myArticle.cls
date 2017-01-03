\NeedsTeXFormat{LaTeX2e}
\ProvidesClass{myArticle}[2014/11/23 My custom report class]

% \PassOptionsToClass{a4paper}{report}
% \ProcessOptions

% Load LaTeX's article class with the `titlepage' option so that \maketitle creates a title page, not just a title block
\LoadClass[titlepage]{article}

% Load packages
\usepackage[utf8]{inputenc}
\usepackage[T1]{fontenc}
\usepackage[top=1.5cm, bottom=1.5cm, left=1.5cm, right=1.5cm]{geometry}
\usepackage[francais]{babel}

% set some space between 2 par
\setlength{\parskip}{.8em}

