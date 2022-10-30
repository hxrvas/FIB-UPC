using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GirarMenu : MonoBehaviour
{
    //0 es el ini enmig, 1 es el de la dreta, 2 es el de la esquerra
    public GameObject voxelG1, voxelG2, voxelG3, T1, T2, T3, panelCompra, panelError, ME, MD;
    Vector3 aux;
    static bool dreta = false;
    static bool esquerra = false;
    int idActiu;
    int money;
    bool P1Comprat = false;
    bool P2Comprat = false;

    public void Start()
    {
        idActiu = 0;
        int a;
        a = PlayerPrefs.GetInt("p1");
        if (a == 1) P1Comprat = true;
        a = PlayerPrefs.GetInt("p2");
        if (a == 1) P2Comprat = true;
    }

    public void BackMainMenu()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        SceneManager.LoadScene("MainMenu");
    }


    public void Dreta()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        dreta = true;
        idActiu = (idActiu + 1) % 3;
    }

    public void Esquerra()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        esquerra = true;
        idActiu = (idActiu - 1) % 3;
    }

    public void pressBuy()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        if ((idActiu == 1 && !P1Comprat ) || (idActiu == 2 && !P2Comprat) || (idActiu == -1 && !P2Comprat) || (idActiu == -2 && !P1Comprat))
        {
            Time.timeScale = 0f;
            if (((idActiu == 1 || idActiu == -2) && money >= 50000) || ((idActiu == 2 || idActiu == -1) && money >= 10000)) panelCompra.SetActive(true);
            else panelError.SetActive(true);
            ME.SetActive(false);
            MD.SetActive(false);
        }
    }

    public void pressNo()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        Time.timeScale = 1f;
        panelCompra.SetActive(false);
        panelError.SetActive(false);
        ME.SetActive(true);
        MD.SetActive(true);
    }

    public void pressYes()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        //baixem els diners que tenim
        int scoreAux = PlayerPrefs.GetInt("score");
        if (idActiu == 1 || idActiu == -2)
        {
            scoreAux -= 50000;
            PlayerPrefs.SetInt("skinId", 1);
            P1Comprat = true;
            PlayerPrefs.SetInt("p1", 1);
        }
        else if (idActiu == 2 || idActiu == -1)
        {
            scoreAux -= 10000;
            PlayerPrefs.SetInt("skinId", 2);
            P2Comprat = true;
            PlayerPrefs.SetInt("p2", 1);
        }
        PlayerPrefs.SetInt("score", scoreAux);
        
        Time.timeScale = 1f;
        panelCompra.SetActive(false);
        panelError.SetActive(false);
        ME.SetActive(true);
        MD.SetActive(true);
    }



    // Update is called once per frame
    void Update()
    {
        money = PlayerPrefs.GetInt("score");
        print(idActiu);
        if (idActiu == 0)
        {
            T1.SetActive(true);
            T2.SetActive(false);
            T3.SetActive(false);
            PlayerPrefs.SetInt("skinId", 0);
        }
        else if (idActiu == 1 || idActiu == -2)
        {
            if (!P1Comprat)
            {
                T1.SetActive(false);
                T2.SetActive(true);
                T3.SetActive(false);
            }
            else
            {
                T1.SetActive(true);
                T2.SetActive(false);
                T3.SetActive(false);
                PlayerPrefs.SetInt("skinId", 1);
            }
        }
        else
        {
            if (!P2Comprat)
            {
                T1.SetActive(false);
                T2.SetActive(false);
                T3.SetActive(true);
            }
            else
            {
                T1.SetActive(true);
                T2.SetActive(false);
                T3.SetActive(false);
                PlayerPrefs.SetInt("skinId", 2);
            }
        }

        if (dreta) {
            dreta = false;
            aux = voxelG1.transform.position;
            voxelG1.transform.position = voxelG2.transform.position;
            voxelG2.transform.position = voxelG3.transform.position;
            voxelG3.transform.position = aux;
        }
        if (esquerra)
        {
            esquerra = false;
            aux = voxelG2.transform.position;
            voxelG2.transform.position = voxelG1.transform.position;
            voxelG1.transform.position = voxelG3.transform.position;
            voxelG3.transform.position = aux;
        }
    }
}
