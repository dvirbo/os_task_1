# os_task_1
עליכם לממש shell שתקבל פקודות ותריץ אותם 

א. רוצו בלולאה הציגו prompt (לדוגמא yes master?) וקילטו קלט מהמשתמש. אם מתקבלת הפקודה EXIT - צאו מהshell שאתם כותבים. (5 נקודות) 

ב. קראו את הספריה הנוכחית (בעזרת getcwd) והציגו אותה בprompt. הכניסו את ההוראות ששיניתם מסעיפים קודמים להערה. (5 נקודות)

ג. אם קיבלתם פקודה המתחילה ב ECHO הדפיסו לstandard output את הפלט המופיע אחרי ECHO (5 נקודות)
לדוגמא הפקודה ECHO HAIDE MACCABI YAFO תציג לפלט הסטנדרטי HAIDE MACCABI YAFO)

ד1. אם קיבלתם פקודה TCP PORT - יפתח לLocalhost קשר TCP (אתם בתפקיד הclient) והסטנדרט output יועתק לשם. (כלומר כל הפלט יצא לסוקט במקום לstdout הרגיל) - 15 נקודות

ד2. בנו server המציג את הפלט שמתקבל. - (10 נקודות)

ה. אם קיבלתם פקודה LOCAL - הסטנדרט output יעבור חזרה לטרמינל. כל socket אם קיים כזה (סעיף ד) יתנתק. - (5 נקודות)

ו. אם קיבלתם פקודה DIR - הציגו את רשימת הקבצים בספריה הנוכחית לפלט הסטנדרטי.
על מנת לעשות זאת תצטרכו לקרוא את רשימת הקבצים בעזרת הפקודות opendir, readdir, closedir.
קראו את דפי הman של הפקודות האלה. - (15 נקודות)

ז. אם קיבלתם פקודה  CD - תצטרכו לשנות ספריה למחיצה שמגיעה כפרמטר אחרי CD (5 נקודות)
לדוגמא אם קיבלתם את הפקודה CD KABILIO - עליכם לשנות ספריה לספריה KABILIO
לצורך זה תצטרכו לקרוא לchdir. האם chdir היא פונקצית ספריה או קריאת מערכת? כתבו את התשובה בהערות (תעוד)

ח. כל פקודה אחת שאתם מקבלים - הריצו אותה בעזרת system (5 נקודות)
האם system היא פונקצית ספריה או קריאת מערכת? כיתבו את התשובה בהערות

ט. ממשו את הסעיף הקודם בעזרת fork, exec, wait ללא system. (15 נקודות)
הכניסו את ההוראות ששיניתם מסעיפים קודמים להערה.

י. אם מתקבלת הוראה COPY SRC DST - העתיקו את הקובץ המופיע בsource ל DST
בצעו זאת בעזרת fopen, fread, fwrite. (10 נקודות)
האם המימוש שלכם משתמש בקריאות מערכת או בפונקציית ספריה? כתבו את התשובות בהערה.

יא. אם מתקבלת הוראה DELETE FILENAME - מחקו את הקובץ המתקבל כFILENAME. עשו זאת בעזרת הוראת unlink.
האם המימוש שלכם משתמש בקריאות מערכת או בפונקצית ספריה? כתבו את התשובה בהערה (5 נקודות)
