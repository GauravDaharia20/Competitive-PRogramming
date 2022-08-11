for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }