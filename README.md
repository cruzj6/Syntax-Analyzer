Syntax-Analyzer
===============
This project analyzes the syntax of a language I created. The user writes the "code" in the input.txt file that is
included and then runs the program. The program will tell you any errors or anywhere it expected an identifier
or it will tell you that your syntax is perfect for the language. Below I included the EBNF for how the grammer 
works for the language and an example of a breakdown of the grammer.

EBNF:
Top Level:
<Taking a Class>  <Classwork> <Homework>

Multiuse rules:
<school thing>  pencil | pen | ruler | calculator | notebook| laptop |professor | book
<grade>  A|B|C|D|E|F
<quality>  great | bad | efficient | useful | reflective

Stuff done in class itself:
<Classwork>  <participation grade> <solo work>
<solo work>  I_need_a <school thing> { and <school thing>} for_my <solo respons>
<solo respons>  <quality> <solo class actions>
<solo class actions>  notes | writing | problems | answers | questions
<participation grade> I_have_a <grade> in_participation [my_grade_is <quality>]

Stuff done at home:
<Homework>   <hw properties> also <what hw is>
<hw properties>  <due> it_is <quality>
<due>  Homework_is_due <day> {and <day>} [Turned_homework_in <day>]
<day>  tomorrow| Monday | Tuesday | Wednesday | Thursday | Friday
<what hw is>  It_is <hw type> requiring <school thing>
<hw type>  project | paper | exercises

Example:
<taking a class>  <classwork><homework>
<classwork>  <participation grade> < solo work> 
I_have_a<grade> in_participation I_need_a <school thing> for_my <solo respons>
I_have_a B in_participation I_need_a pencil for_my <quality><solo class actions>
I_have_a B in_participation I_need_a pencil for_my great writing
