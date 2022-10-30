using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class Control : MonoBehaviour
{
    public SkinnedMeshRenderer skinVoxel;
    public Material skin0, skin1, skin2;

    private void Start()
    {
        int id = PlayerPrefs.GetInt("skinId");
        if (id == 0) skinVoxel.material = skin0;
        else if (id == 1) skinVoxel.material = skin1;
        else if (id == 2) skinVoxel.material = skin2;
    }
    public void NextScene()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        SceneManager.LoadScene("Nivel1");
    }

    public void SkinScene()
    {
        FindObjectOfType<AudioManager>().Play("Button");
        SceneManager.LoadScene("SkinsMenu");
    }

    public void Exit()
    {
        Application.Quit();
    }
}
