using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class PauseMenu : MonoBehaviour
{
    public static bool paused = false;
    public static bool instructions = false;
    static bool insAnt = false;

    public GameObject pauseMenuUI;
    public GameObject instructionsUI;

    void Update()
    {
        if (Input.GetButtonDown("pauseButton") && !instructions)
        {
            FindObjectOfType<AudioManager>().Play("Button");
            if (paused)
            {
                Resume();
            }
            else
            {
                Pause();
            }
        }

        if (instructions && !insAnt)
        {
            InstruccionsActive();
        }
        else if (instructions && Input.GetButtonDown("pauseButton"))
        {
            InstruccionsDesactive();
        }
    }

    public void InstruccionsActive()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        insAnt = true;
        pauseMenuUI.SetActive(false);
        instructionsUI.SetActive(true);
    }

    public void InstruccionsDesactive()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        instructions = false;
        instructionsUI.SetActive(false);
        pauseMenuUI.SetActive(true);
        insAnt = false;     
    }

   public void Resume ()
    {
        FindObjectOfType<AudioManager>().Undampen("Theme");
        pauseMenuUI.SetActive(false);
        Time.timeScale = 1f;
        paused = false;
    }

    void Pause ()
    {
        FindObjectOfType<AudioManager>().Stop("Run");
        FindObjectOfType<AudioManager>().Dampen("Theme");
        pauseMenuUI.SetActive(true);
        Time.timeScale = 0f;
        paused = true;
    }

    public void LoadMenu()
    {
        paused = false;
        FindObjectOfType<AudioManager>().Play("Button");
        Time.timeScale = 1f;
        SceneManager.LoadScene("MainMenu");
    }
    
    public void Instructions()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        instructions = true;
    }

    public void reloadLevel()
    {
        paused = false;
        FindObjectOfType<AudioManager>().Play("Button");
        Time.timeScale = 1f;
        int scene = SceneManager.GetActiveScene().buildIndex;
        SceneManager.LoadScene(scene, LoadSceneMode.Single);
    }


}