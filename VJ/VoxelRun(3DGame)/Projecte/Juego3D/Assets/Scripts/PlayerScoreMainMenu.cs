using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PlayerScoreMainMenu : MonoBehaviour
{
    int playerScore;
    public Text MyText;

    //aconseguim la puntuacio actual
    void Start()
    {
        playerScore = PlayerPrefs.GetInt("score");
        print(playerScore);
        MyText.text = playerScore.ToString() ;
    }
}
