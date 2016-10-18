# Blockbusted
This is the Blockbusted Video Project for CS433


Alright, so so far I've condensed all the versions down
There's a problem with adding a .pro | .pro.user
So therefore you have to make your own project.

Just don't forget to append "sql" to the provided line on your .pro:
"QT       += core gui"

Therefore it'll look like this:
"QT       += core gui sql "


also changed to directory of the database open to ./Blockbusted_db.db
This will eliminiate all variable file paths and play to this relative path instead
Should work if all is unzipped in the same place

