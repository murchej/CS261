set auto-load safe-path /
source ~/.gdb/gdb_dashboard.py
set history save
set verbose off
set print pretty on
set print array off
set print array-indexes on
set python print-stack full
python Dashboard.start()
dashboard -layout registers assembly source stack memory expressions
