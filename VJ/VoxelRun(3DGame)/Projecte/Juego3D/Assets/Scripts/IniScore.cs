using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;


public class IniScore : MonoBehaviour
{
    int playerScore;

    private void Start()
    {
        playerScore = 0;
        PlayerPrefs.SetInt("score", playerScore);
        //les dos skins comencen sense estar comprades
        PlayerPrefs.SetInt("p1", 0);
        PlayerPrefs.SetInt("p2", 0);
        //ini id skin
        PlayerPrefs.SetInt("skinId", 0);
        Invoke("loadMainMenu", 4f);
    }

    void loadMainMenu()
    {
        SceneManager.LoadScene("MainMenu");
    }
}