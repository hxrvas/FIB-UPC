using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class CreditsScript : MonoBehaviour
{
    // Update is called once per frame
    void Update()
    {
        Invoke("MainMenu", 20f);
    }

    public void MainMenu()
    {
        SceneManager.LoadScene("MainMenu");
    }
}
