import pandas as pd

def duplicate_emails(person: pd.DataFrame) -> pd.DataFrame:
    res = person.groupby(['email']).id.count().reset_index()
    return res.loc[res['id'] > 1, ['email']].rename(columns={'email' : 'Email'})